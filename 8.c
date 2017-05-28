#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
	pid_t pid;
	if((pid=fork())<0) {
		printf("Error in first fork\n");
	} else if(pid==0) {
		printf("First Child pid = %d\tParent pid = %d\n",getpid(),getppid());
		if((pid=fork())<0)
			printf("Second fork error\n");
		else if(pid>0)
			exit(0);
		sleep(2);
		printf("Second child pid = %d\tParent pid = %d\n",getpid(),getppid());
		exit(0);
	}
	if(waitpid(pid,NULL,0)!=pid)
		printf("Waitpid error\n");
	return 0;
}
