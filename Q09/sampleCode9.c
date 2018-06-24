#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXLEN 1024

int main()
{
    int slen, flag;
    char buff[MAXLEN], *p, *q;
    while(fgets(buff, MAXLEN, stdin) != NULL)
    {
        flag = 1;
        slen = strlen(buff) - 1;
        buff[slen] = buff[slen] == '\n' ? '\0' : buff[slen];
        for(p = &buff[0], q = &buff[strlen(buff) - 1]; q >= p; p++, q--)
        {
            if(*p != *q)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("%s\n", buff);
        }
    }
    return 0;
}
