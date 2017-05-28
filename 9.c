#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int sys(const char *cmdstr) 
{
        pid_t pid;
        int status;
        if (!cmdstr)
                return 1;
        if ((pid = fork()) < 0)
                status = -1;
        if (pid == 0) 
        {
                execl("/bin/sh", "sh", "-c", cmdstr, NULL);
                _exit(127);
        }
        else
                while(waitpid(pid, NULL, 0) < 0) 
                        if (errno != EINTR) 
                        {
                                status = -1;
                                break;
                        }
        return status;
}

int main(int argc, char *argv[]) 
{
        if( sys(argv[1]) < 0)
                printf("sys error\n");
        _exit(0);
}
