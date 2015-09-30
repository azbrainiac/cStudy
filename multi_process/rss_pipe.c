#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void error(char *msg){
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

void open_url(char *url)
{

	char launch[255];
	//printf("x-www-browser '%s' &", url);
	//sprintf(launch, "cmd /c start %s", url);
	//system(launch);
	sprintf(launch, "x-www-browser %s", url);
	system(launch);
	//sprintf(launch, "open '%s'", url);
	//system(launch);
}

int main(int argc, char const *argv[])
{
	char *phrase = argv[1];
	char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/rss.xml", NULL};

	/* файловые дескрипторы для канала */
	int fd[2];

	if(pipe(fd) == -1){
		error("Не могу создать канал");
	}

	pid_t pid = fork();

	if(pid == -1){
		error("Не могу клонировать процесс");
	}

	if(!pid){
		/*Перенаправляем стандартный вывод в конец канала, выделенного для записи*/
		dup2(fd[1], 1);
		/*Дочерний процесс не будет считывать из канала, поэтому закрываем конец 
		канала, выделенного для чтения*/
		close(fd[0]);
		if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1){
			error("Не могу запустить скрипт");
		}
	}
	/*перенаправление стандартного ввода в конец канала, выделенного для чтения*/
	dup2(fd[0], 0);
	/*закрытие конца канала, выделенного для записи родительского процесса*/
	close(fd[1]);

	char line[255];
	/*стандартный ввод stdin подключен к каналу. вместо stdin можно fd[0]*/
	while(fgets(line, 255, stdin)){
		if(line[0] == '\t')
			open_url(line + 1);
	}
	int pid_status;
	if(waitpid(pid, &pid_status, 0) == -1){
		error("Ошибка во время ожидания дочернего процесса");
	}

	return 0;
}

