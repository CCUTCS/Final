#include<stdio.h>

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d\n%d\n%d\n", a + b, a - b, a * a - b * b);
    }


    return 0;
}
