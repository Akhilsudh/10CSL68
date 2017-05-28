%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#define MAX 100

	int genREindex(const char*);
	signed char prod[MAX][MAX];
	int count = 0, i, j;
	char temp[MAX+MAX], temp2[MAX+MAX];
%}

%token ALPHA
%left '|'
%left '.'
%nonassoc '*' '+'

%%

S:re '\n'	{
				printf("the right most derivation is \n");
				for (i = count - 1; i >= 0; --i) {
					if (i == count - 1)	{
						printf("\nre\t=>\t");
						strcpy(temp, prod[i]);
						printf("%s", prod[i]);
					}
					else {
						printf("\n  \t=>\t");
						j = getREindex(temp);
						temp[j] = '\0';
						sprintf(temp2, "%s%s%s", temp, prod[i], (temp + j + 2));
						printf("%s", temp2);
						strcpy(temp, temp2);
					}

				}
				printf("\n");
				exit(0);
			}
re 	:ALPHA	{	
				temp[0] = yylval;
				temp[1] = '\0';
				strcpy(prod[count++], temp);}
	|'('re')'	{strcpy(prod[count++], "(re)");}
	|re'*'		{strcpy(prod[count++], "re*");}
	|re'+'		{strcpy(prod[count++], "re+");}
	|re'|'re 	{strcpy(prod[count++], "re|re");}
	|re'.'re 	{strcpy(prod[count++], "re.re");}
	;
%%

int main(int argc, char *argv[]) 
{
	yyparse();
	return 0;
}

yylex() 
{
	signed char ch = getchar();
	yylval = ch;
	if (isalpha(ch))
		return ALPHA;
	return ch;
}

yyerror() 
{
	fprintf(stderr,"Invalid regular expression\n");
	exit(1);
}

int getREindex(const char *str) 
{
	int i = strlen(str) - 1;
	for (; i >= 0; --i)
		if (str[i] == 'e' && str[i-1] == 'r')
			return i - 1;
}
