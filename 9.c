#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int mySystem(const char *cmdstr) {
	pid_t pid;
	int status;
	if(cmdstr==NULL)
		return 1;
	if((pid=fork())<0)
		status = -1;
	else if(pid==0) {
		execl("/bin/sh","sh","-c",cmdstr,(char *)0);
		_exit(127);
	} else {
		while(waitpid(pid,&status,0)<0) {
			if(errno != EINTR) {
				status = -1;
				break;
			}
		}
	}
	return status;
}
int main(int argc, char **argv) {
	int status,i;
	for(i=1;i<argc;i++)
		if((status=mySystem(argv[i]))<0)
			printf("mySystem(%s) error\n",argv[i]);
	return 0;
}
