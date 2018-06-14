// term frequency analysis using 1D linkedlist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXLEN 1024

// structure declare
typedef struct listNode
{
    int cnt;
    char *p2key;
    struct listNode *p2next;
}   listNode;

// function declaration
// extern char *strdup(const char *__s);
listNode *listFind(listNode *head, char *patt); // 查找 key 是否已存在 list 中，若存在，回傳該節點記憶體位置，否則回傳 null
void listAppend(listNode **head, listNode **tail, char *patt); // 在 list 的尾巴 append 一個新節點 (先出現的詞再出現的機率會比較高)
int desc(const void *a, const void *b); // 比較函數宣告，按降序排序
int asce(const void *a, const void *b); // 比較函數宣告，按升序排序
void listShow(listNode *trav, int listlen, int (*cmp)(const void *a, const void *b)); // 把 list 結果印出，可以把比較函數傳入，選擇按照升、降序排序
void listFree(listNode *curr); // 程式結束前把宣告的節點都 free 掉

// main function
int main(int argc, char **argv)
{
    int listlen = 0, slen;
    char buff[MAXLEN];
    listNode *head = NULL, *tail = NULL, *p2node = NULL;
    while(fgets(buff, MAXLEN, stdin) != NULL)
    {
        slen = strlen(buff) - 1;
        buff[slen] = buff[slen] == '\n' ? '\0' : buff[slen];
        if((p2node = listFind(head, buff)) != NULL) // 如果 key 已存在，把該 key 的計數加一
        {
            p2node -> cnt ++;
        }
        else // 若是不存在把 key append 在 list 的後面(Insert at tail)
        {
            listAppend(&head, &tail, buff); 
            listlen++;
        }
    }
    listShow(head, listlen, NULL); // 按照插入順序、按照升序排序、按照降序排序
    // listShow(head, listlen, asce);
    // listShow(head, listlen, desc);
    listFree(head); // 釋放記憶體
    return 0;
}

listNode *listFind(listNode *head, char *patt)
{
    if(head == NULL)
    {
        return NULL;
    }
    listNode *curr = head;
    while(curr != NULL)
    {
        if(strcmp(curr -> p2key, patt) == 0)
        {
            return curr;
        }
        curr = curr -> p2next;
    }
    return NULL;
}

void listAppend(listNode **head, listNode **tail, char *patt)
{
    listNode *temp = (listNode *) malloc(sizeof(listNode));
    assert(temp != NULL);
    temp -> p2key = strdup(patt);
    assert(temp -> p2key != NULL);
    temp -> cnt = 1;
    temp -> p2next = NULL;
    if((*head) == NULL)
    {
        (*head) = (*tail) = temp;
    }
    else
    {
        temp -> p2next = *head;
        *head = temp;
    }
}

int desc(const void *a, const void *b)
{
    return (*((listNode**)a)) -> cnt < (*((listNode**)b)) -> cnt;
}

int asce(const void *a, const void *b)
{
    return (*((listNode**)a)) -> cnt > (*((listNode**)b)) -> cnt;
}

void listShow(listNode *trav, int listlen, int (*cmp)(const void *a, const void *b))
{
    listNode **p2list = (listNode **) malloc(sizeof(listNode *) * listlen);
    assert(p2list != NULL);
    int idx = 0, i;
    while(trav != NULL)
    {
        p2list[idx++] = trav;
        trav = trav -> p2next;
    }
    if(cmp != NULL)
    {
        qsort(p2list, listlen, sizeof(p2list[0]), cmp);
    }
    for(i = 0; i < idx; i++)
    {
        printf("%d\t%s\n", p2list[i] -> cnt, p2list[i] -> p2key);
    }
    free(p2list);
}

void listFree(listNode *curr)
{
    listNode *prev;
    while(curr != NULL)
    {
        prev = curr;
        curr = curr -> p2next;
        free(prev -> p2key);
        free(prev);
    }
}