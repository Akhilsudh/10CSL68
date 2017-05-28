#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void callMe(int sig_no) {
	printf("Hello\n");
}
int main() {
	struct sigaction action;
	while(1) {
		action.sa_handler=(void(*)(int))callMe;
		sigaction(SIGALRM,&action,0);
		alarm(2);
		pause();
	}
	return 0;
}
