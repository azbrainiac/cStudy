#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void error(char *msg){
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int main(int argc, char const *argv[])
{
	char const *phrase = argv[1];
	char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/rss.xml", NULL};
	FILE *f = fopen("rsslog.txt", "w");
	pid = fork();
	if(pid == -1){
		error("Не могу клонировать процесс");
	}
	if(!pid){
		if(dup2(fileno(f),1) == -1){
			error("не получилось перенаправить стандартный вывод");
		}
		if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1){
			error("Не могу запустить скрипт");
		}
	}
	return 0;
}