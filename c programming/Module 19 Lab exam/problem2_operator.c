#include <stdio.h>

int main()
{
   int i=0, sum=0, a, b;
   char s[20];
   scanf("%s", &s);

   scanf("%d %d", &a, &b);

   while(s[i] != '\0')
   {
      if(s[i] == '+')
      {
         sum = sum + a + b;
      }
      else if (s[i] == '*')
      {
         sum = sum + (a *b);
      }

      i++;
   }

   printf("%d", sum);

   return 0;
}
