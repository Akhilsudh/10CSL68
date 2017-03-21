#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>

int main()
{
	long res;
	
	if((res = sysconf(_SC_CLK_TCK)) == -1)
	{
		printf("Error in sysconf\n");
	}
	else
	{
		printf("Number of clock ticks are = %d \n",res);
	}

	if((res = sysconf(_SC_CHILD_MAX)) == -1)
	{
		printf("Error in sysconf\n");
	}
	else
	{
		printf("Maximum number of child processes owned by a process are = %d \n",res);
	}

	if((res = pathconf("/",_PC_PATH_MAX)) == -1)
	{
		printf("Error in pathconf \n");
	}
	else
	{
		printf("Maximum path length is = %d \n",res);
	}

	if((res = pathconf("1.c",_PC_NAME_MAX)) == -1)
	{
		printf("Error in pathconf \n");
	}
	else
	{
		printf("Maximum number of characters in a file are = %d \n",res);
	}

	if((res = sysconf(_SC_OPEN_MAX)) == -1)
	{
		printf("Error in sysconf \n");
	}
	else
	{
		printf("Maximum number of open files are = %d \n",res);
	}

	return 0;
}