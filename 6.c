#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void customPrint(char *);

int main()
{
        pid_t pid;
        if ((pid = fork()) < 0)
                printf("fork error\n");
        else if (pid == 0)
                customPrint("output from child\n");
        else
                customPrint("output from parent\n");
        exit(0);
}
void customPrint(char *str)
{
        char *ptr;
        int c;
        setbuf(stdout,NULL);
        for(ptr = str;(c = *ptr++)!=0;)
                putc(c,stdout);
}
