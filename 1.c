#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
int main() {
	long res;
	if((res=sysconf(_SC_CLK_TCK))==-1)
		printf("Error in _SC_CLK_TCK\n");
	else printf("No of clock ticks=%ld\n",res);
	if((res=sysconf(_SC_CHILD_MAX))==-1)
		printf("Error in _SC_CHILD_MAX\n");
	else printf("Max no of child process=%ld\n",res);
	if((res=pathconf("/",_PC_PATH_MAX))==-1)
		printf("Error in _PC_CHILD_MAX\n");
	else printf("Max path length=%ld\n",res);
	if((res=pathconf("1.c",_PC_NAME_MAX))==-1)
		printf("Error in _PC_NAME_MAX\n");
	else printf("Max no of character in a file name=%ld\n",res);
	if((res=sysconf(_SC_OPEN_MAX))==-1)
		printf("Error in _SC_OPEN_MAX\n");
	else printf("Max no of open files per process=%ld\n",res);
	return 0;
}
