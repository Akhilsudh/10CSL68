%{
	#include<stdio.h>
	#include<ctype.h>
	#include<stdlib.h>
	#include<string.h>
	#define MAX 100
	int getREindex(const char *);
	signed char productions[MAX][MAX];
	int count = 0,i,j;
	char temp[MAX+MAX],temp1[MAX+MAX];
%}
%token ALPHA
%left '|'
%left '.'
%nonassoc '*' '+'
%%
S	:	re'\n'		{	printf("Right most derivation:\n");
					for(i=count-1;i>=0;--i) {
						if(i==(count-1)) {
							printf("\nre\t=>\t");
							strcpy(temp,productions[i]);
							printf("%s",productions[i]);
						} else {
							printf("\n\t=>\t");
							j=getREindex(temp);
							temp[j]='\0';
							sprintf(temp1,"%s%s%s",temp,productions[i],(temp+2+j));
							printf("%s",temp1);
							strcpy(temp,temp1);
						}
					}
					printf("\n");
					exit(0);
				}	;
re	:	ALPHA		{	temp[0]=yylval;
					temp[1]='\0';
					strcpy(productions[count++],temp);	}
	|	'('re')'	{	strcpy(productions[count++],"(re)");	}
	|	re'*'		{	strcpy(productions[count++],"re*");	}
	|	re'+'		{	strcpy(productions[count++],"re+");	}
	|	re'|'re		{	strcpy(productions[count++],"re|re");	}
	|	re'.'re		{	strcpy(productions[count++],"re.re");	}
	;
%%
int main(int argc, char **argv) {
	yyparse();
	return 0;
}
yylex() {
	signed char ch = getchar();
	yylval = ch;
	if(isalpha(ch))
		return ALPHA;
	return ch;
}
yyerror() {
	fprintf(stderr,"Invalid expression\n");
	exit(1);
}
int getREindex(const char *str) {
	int i=strlen(str)-1;
	for(;i>=0;--i) {
		if(str[i]=='e'&&str[i-1]=='r')
			return i-1;
	}
}
