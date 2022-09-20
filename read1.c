#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int fd;
	char buf[10];

	fd = open("./test.txt", O_RDONLY);
	printf("fd : %zd\n",read(fd, buf, 10));
	printf("buf : %s\n", buf);
	printf("buf[9] : %d\n", buf[9]);
}
