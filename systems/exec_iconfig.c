#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
		if (execlp("ipconfig", "ipconfig", NULL) == -1)
		{
			fprintf(stderr, "Не удалось запустить ipconfig: %s\n", strerror(errno));
			return 1;
		}
	return 0;
}