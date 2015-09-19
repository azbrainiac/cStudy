#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	char *feeds[] = {"http://rss.cnn.com/rss/edition_world.rss", 
					"http://feeds.bbci.co.uk/news/rss.xml"};
	int times = 2;
	char const *phrase = argv[1];

	int i;
	for (i = 0; i < times; i++)
	{
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		char *vars[] = {var, NULL};
		pid_t pid = fork();
		if(pid == -1){
			fprintf(stderr, "Не могу клонировать процесс:%s\n", strerror(errno));
			return 1;
		}
		if(!pid){
			if(execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1){
				fprintf(stderr, "Не могу запустить скрипт:%s\n", strerror(errno));
				return 1;
			}
		}
	}

	return 0;
}