#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int fd;
	char buff[256];
	if(argc != 2 && argc !=3)
	{
		printf("Invalid number of arguements\n");
		return 0;
	}
	mkfifo(argv[1], S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO);
	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("Contents of the FIFO file are \n");
		while(read(fd, buff, sizeof(buff)) > 0)
		{
			printf("%s\n",buff);
		}
	}
	else
	{
		fd = open(argv[1], O_WRONLY);
		write(fd, argv[2], strlen(argv[2]));
	}
	close(fd);
}