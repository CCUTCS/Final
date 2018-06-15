
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bst{
    char str[128];
    int cnt;
    struct bst *lnode;
    struct bst *rnode;
};


void insert(struct bst* root, char input[]);
void print_inorder(struct bst* root);
void freebst(struct bst* root);

int main()
{
    char input[1024];
    struct bst *root = NULL;
    int start = 1;
    while(fgets(input, 1024, stdin))
    {
        if(input[0] == '\n')
         continue;
        if(start)
        {
            root = (struct bst*) malloc(sizeof(struct bst));
            strcpy(root->str, input);
            root->lnode = root->rnode = NULL;
            root->cnt = 1;
            start = 0;
        }
        else
        {
            insert(root, input);
        }
    }

    print_inorder(root);
    freebst(root);

    return 0;
}

void insert(struct bst* root, char input[])
{
    if(strcmp(root->str, input) < 0)
    {
        if(root->rnode == NULL)
        {
            root->rnode = (struct bst*) malloc(sizeof(struct bst));
            strcpy(root->rnode->str, input);
            root->rnode->cnt = 1;
            root->rnode->rnode = root->rnode->lnode = NULL;
        }
        else
        {
            insert(root->rnode, input);
        }
    }
    else if(strcmp(root->str, input) > 0)
    {
        if(root->lnode == NULL)
        {
            root->lnode = (struct bst*) malloc(sizeof(struct bst));
            strcpy(root->lnode->str, input);
            root->lnode->cnt = 1;
            root->lnode->rnode = root->lnode->lnode = NULL;
        }
        else
        {
            insert(root->lnode, input);
        }
    }
    else
    {
        root->cnt++;
    }
}


void print_inorder(struct bst* root)
{
    if(root == NULL)
        return ;
    print_inorder(root->lnode);
    printf("%d\t%s", root->cnt , root->str);
    print_inorder(root->rnode);
}

void freebst(struct bst* root)
{
    if(root == NULL)
        return;
    freebst(root->lnode);
    freebst(root->rnode);
    free(root);
}
