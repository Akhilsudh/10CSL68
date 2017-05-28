#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
int main(int argc, char* argv[]) {
	struct flock filelock;
	int fd;
	char buf[50];
	fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		printf("Error\n");
		return 1;
	}
	lseek(fd,-100,SEEK_END);
	filelock.l_whence = SEEK_CUR;
	filelock.l_start = 0;
	filelock.l_len = 100;
	if(fcntl(fd,F_GETLK,&filelock) == 0) {
		printf("File is locked\n");
		return 0;
	} else {
		printf("File not locked \n");
		filelock.l_type = F_WRLCK;
		filelock.l_whence = SEEK_END;
		filelock.l_start = 0;
		filelock.l_len = 100;
		if(fcntl(fd,F_SETLK,&filelock) == -1) {
			printf("Error in locking the file\n");
			return 1;
		} else {
			printf("File is locked\n");
			lseek(fd,-50,SEEK_END);
			printf("Contents of the locked file are = \n");
			if(read(fd,buf,sizeof(buf))) {
				printf("%s\n",buf);
			}
		}
	}
	filelock.l_type = F_UNLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;
	if(fcntl(fd, F_SETLKW, &filelock) == -1) {
		printf("Error\n");
		return 1;
	} else {
		printf("File is unlocked\n");
	}
	return 0;
}
