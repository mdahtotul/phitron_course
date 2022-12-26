#include <stdio.h>

int main()
{
   int N, i=0, plus=0, min=0;
   scanf("%d", &N);
   char s[N];
   scanf("%s", &s);

   int t_plus = 0, t_min= 0;
   while(s[i] != '\0')
   {
      if(s[i] == s[i+1] && s[i] == '+')
      {
         t_plus++;
         if(t_plus > plus)
         {
            plus = t_plus;
         }
            t_min = 0;
      }
      else if(s[i] == s[i+1] && s[i] == '-')
      {
         t_min++;
         if(t_min > min)
         {
            min = t_min;
         }
            t_plus = 0;
      }

      i++;
   }

   if(plus > min)
      printf("%d", plus + 1);
   else
      printf("%d", min + 1);

   return 0;
}
