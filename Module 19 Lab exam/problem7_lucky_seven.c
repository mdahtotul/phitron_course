#include <stdio.h>
#include <string.h>

int main()
{
   int T, i, j;
   scanf("%d", &T);

   for(i=0; i<T; i++)
   {
      char s[20];
      char r_s[20];
      scanf("%s", &s);
      int len = strlen(s);
      for(j=0; j<len; j++)
      {
         r_s[len-1-j] = s[j];
      }
      int flag=0;
      for(j=0; j<len; j++)
      {
         if(s[j] != r_s[j])
         {
            flag = 1;
            break;
         }
      }
      if (flag == 1)
      {
         printf("Case #1: Not Palindrome\n");
      }
      else
      {
         if(len > 7)
         {
            printf("Case #2: %c%d%c\n", s[0], len-2, s[len-1]);
         }
         else
         {
            printf("Case #3: %s\n",s);
         }
      }

   }

   return 0;
}
