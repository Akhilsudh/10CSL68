#include <stdio.h>

int main(int argc, char** argv, char** envp)
{
	int i;
	while (envp[i] != NULL)
		printf("%s\n\n", envp[i++]);
	return 0;
}
