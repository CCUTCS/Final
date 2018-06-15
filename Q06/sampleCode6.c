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
        int slen = strlen(buff) - 1;
        buff[slen] = buff[slen] == '\n' ? '\0' : buff[slen];
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
        printf("%s\n", buff);
    }
    //printf("\n");
    return 0;
}
