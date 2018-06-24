#include <stdio.h>
int main()
{
  int x, y;
  char buf[1024], optr;
  while(fgets(buf, 1024, stdin) != NULL)
  {
    sscanf(buf, "%c%d%d", &optr, &x, &y);
    switch(optr)
    {
      case '+':
        printf("%d\n", x+y);
        break;
      case '-':
        printf("%d\n", x-y);
        break;
      case '*':
        printf("%d\n", x*y);
        break;
      case '/':
        printf("%d\n", x/y);
        break;
      default:
        break;
    }
  }
  return 0;
}
