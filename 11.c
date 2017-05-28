#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gen(char c[], char s1[], char s2[], int flag) 
{
        int l1=100, l2=101, l3=102;
        printf("if %s GOTO %d", c, l1);
        printf("\n\t GOTO %d", l2);
        printf("\n%d:\t%s", l1, s1);
        if (!flag)
                printf("\n%d:\n", l2);
        else {
                printf("\n\t GOTO %d", l3);
                printf("\n%d:\t%s", l2, s2);
                printf("\n%d:\n", l3);
        }
}

int main() 
{
        int count = 0, flag = 0, i = 0;
        char stmt[60], tok[10][20], *p;
        printf("Format of if statement\nExample\n");
        printf("if (a<b) then (s,a)\n");
        printf("if (a<b) then (s,a) else (s,b)\n");
        printf("Enter statement\n");
        scanf("%[^\n]", stmt);
        p = strtok(stmt, " ");
        while( p) {
                strcpy(tok[i++], p);
                if(!strcmp(p, "else"))
                        flag = 1;
                p = strtok(NULL, " ");
        }
        if (strcmp(tok[2], "then")) {
                printf("Invalid expression \n");
                return 0;
        }
        else if(flag & strcmp(tok[4], "else")) {
                printf("Invalid expression\n");
                return 0;
        }
        else 
                gen(tok[1], tok[3], tok[5], flag);
        return 0;
}
