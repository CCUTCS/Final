// 範例測資最後面要補換行
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXLEN 1024
#define MAXWORD 8192

int cmp(const void *a, const void *b)
{
    return strcmp((*(char**)a), (*(char**)b));
}
int main()
{
    char buff[MAXLEN];
    char **ptr = (char **) malloc(sizeof(char *) * MAXWORD);
    assert(ptr != NULL);
    int i = 0, j = 0;
    while(fgets(buff, MAXLEN, stdin) != NULL)
    {
        ptr[i++] = (char *) strdup(buff);      
    }
    qsort(ptr, i, sizeof(char *), cmp);
    for(j = 0; j < i; j++)
    {
        printf("%s", ptr[j]);
        free(ptr[j]);
    }
    free(ptr);
    return 0;
}