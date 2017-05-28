#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void printChar(char *str) {
	char *ptr;	
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;(c=*ptr++)!=0;)
		putc(c,stdout);
}
int main() {
	pid_t pid;
	pid = fork();
	if(pid<0) {
		printf("Fork error\n");
	} else if(pid==0) {
		printChar("Output from child\n");
	} else {
		printChar("Output from parent\n");
	}
	return 0;
}
