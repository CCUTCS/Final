#include<stdio.h>
#include<string.h>

int main()
{
    char input[1024];
    while(fgets(input, 1024, stdin))
    {
        int a = 0, b = 0, tmp = 0, ans;
        char *c = input;
        while(*c != '\n' && *c != '\r')
        {
            if(*c >= '0' & *c <= '9')
            {
                c--;
                if(*c == ' ') tmp++;
                c++;
                if(tmp == 1)
                    a = a * 10 + *c - '0';
                if(tmp == 2)
                    b = b * 10 + *c - '0';

            }
            c++;
        }
        switch(input[0])
        {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        default:
            break;
        }
        printf("%d\n", ans);
    }

    return 0;
}
