#include <stdio.h>
#include <string.h>

int main()
{
   int n, i;
   printf("Total words : ");
   scanf("%d", &n);
   char w[100];

   for(i=0; i<n; i++)
   {
      scanf("%s", w);

      int len = strlen(w) - 1;

      if(len > 4)
      {
         printf("%c%d%c", w[0], len - 1, w[len]);
      }
      else
      {
         puts(w);
      }
   }

   return 0;
}
