#include <stdio.h>
#include <string.h>
void reverse(char*, int, int);

int main()
{
   char a[100];

   gets(a);

   reverse(a, 0, strlen(a)-1);

   printf("%s\n", a);

   return 0;
}

void reverse(char *x, int begin, int end)
{
   char c;

   if (begin >= end)
      return;

   c          = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end)   = c;

   reverse(x, ++begin, --end);
}