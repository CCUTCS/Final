#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXLEN 1024

typedef struct listNode
{
    char *p2key;
    struct listNode *p2next;
} listNode;

int main()
{
    char buff[MAXLEN];
    listNode *head = NULL, *temp, *prev;
    while(fgets(buff, MAXLEN, stdin) != NULL)
    {
        int slen = strlen(buff);
        buff[slen - 1] = buff[slen - 1] == '\n' ? '\0' : buff[slen - 1];
        if(head == NULL)
        {
            head = (listNode *) malloc(sizeof(listNode));
            assert(head != NULL);
            head -> p2key = strdup(buff);
            head -> p2next = NULL;
        }
        else
        {
            temp = (listNode *) malloc(sizeof(listNode));
            assert(temp != NULL);
            temp -> p2key = strdup(buff);
            temp -> p2next = head;
            head = temp;
        }
    }
    for(temp = head; temp != NULL;)
    {
        printf("%s\n", temp -> p2key);
        free(temp -> p2key);
        prev = temp;
        temp = temp -> p2next;
        free(prev);
    }
    return 0;
}
