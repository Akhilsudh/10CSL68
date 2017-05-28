#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char **argv) {
	if(argc!=3 && argc!=4) {
		printf("Usage error\n");
		return 1;
	}
	if(argc==3) {
		if(strcmp(argv[1],argv[2])) {
			if(link(argv[1],argv[2])!=-1)
				printf("Link success\n");
			else
				printf("Link creation error\n");
		} else printf("Parameter usage error\n");
	} else {
		if(!strcmp(argv[1],"-s")&&strcmp(argv[2],argv[3])) {
			if(symlink(argv[2],argv[3])!=-1)
				printf("Symlink success\n");
			else
				printf("Symlink creation error\n");
		} else printf("Parameter usage error\n");
	}
	return 0;
}
