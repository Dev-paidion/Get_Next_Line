

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
	ssize_t fd, n1, n2;	
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	fd = open("./test.txt", O_RDONLY);
	printf("fd : %zd\n", fd);
	if (fd < 0)
	{
		printf("Failed to OPEN FILE");
	}

	n1 = read(fd, buf1, BUFFER_SIZE );
	n2 = read(fd, buf2, BUFFER_SIZE );
	if ( n1 < 0 || n2 < 0 )
	{
		close(fd);
		printf("Failed to OPEN FILE");
	}
	buf1[n1] = '\0';
	buf2[n2] = '\0';

	printf(" n1 = %zd, buf1 = %s\n n2 = %zd, buf2 = %s\n", n1, buf1, n2, buf2);
	close(fd);
	return (0);
}
