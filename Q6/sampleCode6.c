#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXLINE 1024
int main()
{
    char buff[MAXLINE], *p, *q;
    while(fgets(buff, MAXLINE, stdin) != NULL)
    {
        for(p = buff; *p != '\0';)
        {
            if(*p == ' ' || *p == '\t' || *p == '\n')
            {
                *p = '\n';
                while(*p == ' ' || *p == '\t' || *p == '\n')
                {
                    p++;
                }
            }
            else
            {
                p++;
            }
        }
        printf("%s", buff);
    }
    printf("\n");
    return 0;
}