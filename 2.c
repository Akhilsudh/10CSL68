#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>

int main()
{
	#ifdef _POSIX_JOB_CONTROL
		printf("System supports job control \n");
	#else
		printf("System doesn't support job control \n")
	#endif

	#ifdef _POSIX_NO_TRUNC
		printf("System supports path trunc option \n");
	#else
		printf("System doesn't support path trunc \n");
	#endif

	#ifdef _POSIX_SAVED_IDS
		printf("System supports saved set UID and GID \n");
	#else
		printf("System doesn't support saved set IDs \n");
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED	
		printf("System supports owner change in files \n");
	#else
		printf("System doesn't support owner change of files \n");
	#endif

	#ifdef _POSIX_VDISABLE
		printf("System supports VDISBLE \n");
	#else
		printf("System doesn't support VDISABLE \n");
	#endif

	return 0;
}