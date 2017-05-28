#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv) {
	int fd;
	char buf[256];
	if(argc!=2&&argc!=3) {
		printf("Usage error\n");
		return 1;
	}
	//mfifo(argv[1],S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO);
	mkfifo(argv[1],S_IFIFO|0777);
	if(argc==2) {
		fd=open(argv[1],O_RDONLY);
		printf("\nContent of fifo are:\n");
		while(read(fd,buf,sizeof(buf))>0)
			printf("%s\n",buf);
	} else {
		fd=open(argv[1],O_WRONLY);
		write(fd,argv[2],strlen(argv[2]));
	}
	close(fd);
}
