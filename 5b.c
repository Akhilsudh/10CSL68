#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv) 
{
	if(argc == 3)
		if(link(argv[1], argv[2]) == -1)
			printf("Error has occurred\n");
		else
			printf("New hard link created\n");
	else
		printf("Insufficient arguements\n");
	return 0;
}
