#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
int main() {
	#ifdef _POSIX_JOB_CONTROL
		printf("System supports job control=%d\n",_POSIX_JOB_CONTROL);
	#else
		printf("System doesn't support job control\n");
	#endif

	#ifdef _POSIX_SAVED_IDS
		printf("System supports saved set-uid and set-gid=%d\n",_POSIX_SAVED_IDS);
	#else
		printf("System doesn't supports saved set-uid and set-gid\n");
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED
		printf("System supports change ownership permission=%d\n",_POSIX_CHOWN_RESTRICTED);
	#else
		printf("System doesn't supports change ownership permission\n");
	#endif
	
	#ifdef _POSIX_VDISABLE
		printf("System supports disabling special characters=%d\n",_POSIX_VDISABLE);
	#else
		printf("System doesn't support disabling special characters\n");
	#endif

	#ifdef _POSIX_NO_TRUNC
		printf("System supports pathname trunc options=%d\n",_POSIX_NO_TRUNC);
	#else
		printf("System doesn't support pathname trunc option\n");
	#endif
	return 0;
}
