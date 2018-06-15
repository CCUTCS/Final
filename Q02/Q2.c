#include<stdio.h>

int main()
{
    int num;
    int flag;
    while(scanf("%d", &num) != EOF)
    {
        int i;
        flag = 1;
        for(i = 2 ; i * i <= num ; i++)
        {
            if(num % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag) printf("%d\n", num);
    }
    return 0;
}

