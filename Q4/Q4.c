#include<stdio.h>

int main()
{
    char input[1024];
    int arr[105], cnt;
    int i, j;
    cnt = 0;
    while(fgets(input, 1024, stdin))
    {
        char *c = input;
        int tmp = 0;
        while(*c != '\n' && *c != '\r' && c != NULL)
        {
            tmp = tmp * 10 + *c - '0';
            c++;
        }
        arr[cnt++] = tmp;
    }
    for(i = 0 ; i < cnt ; i++)
    {
        for(j = 0 ; j < cnt ; j++)
        {
            if(arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for(i = 0 ; i < 5 ; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
