#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void callme(int signo) 
{
    printf("Hello!\n");
}

int main() 
{
    struct sigaction action;
    action.sa_handler = (void(*)(int))callme;
    sigaction(SIGALRM,&action,0);
    alarm(2);
    sleep(2);
    return 0;
}
