#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void gen(char c[], char s1[], char s2[], int elseFlag) {
	int l1=100,l2=200,l3=300;
	printf("\n\tIF %s GOTO %d",c,l1);
	printf("\n\tGOTO %d",l2);
	printf("\n%d  :  %s",l1,s1);
	if(!elseFlag)
		printf("\n%d  :\n",l2);
	else {
		printf("\n\tGOTO %d",l3);
		printf("\n%d  :  %s",l2,s2);
		printf("\n%d  :\n",l3);
	}
}

int main() {
	int elseFlag=0,i=0;
	char token[100][10],stmt[50];
	char *pch;
	printf("if (a<b) then (S,a)\n");
	printf("if (a<b) then (S,a) else (S,b)\n");
	printf("Enter the string:\n");
	scanf("%[^\n]",stmt);
	pch = strtok(stmt," ");
	while(pch!=NULL) {
		strcpy(token[i++],pch);
		if(!strcmp(pch,"else"))
			elseFlag = 1;
		pch = strtok(NULL," ");
	}
	if(strcmp(token[0],"if")!=0) {
		printf("Invalid expression\n");
		return 1;
	} else if(strcmp(token[2],"then")!=0) {
		printf("Invalid expression\n");
		return 1;
	} else if(elseFlag&&strcmp(token[4],"else")!=0) {
		printf("Invalid expression\n");
		return 1;
	}
	gen(token[1],token[3],token[5],elseFlag);
	return 0;
}
