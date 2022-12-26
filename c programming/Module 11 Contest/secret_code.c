#include <stdio.h>

int main()
{
   int T, c, i, j;
   scanf("%d", &T);

   int arr[T];

   for(i=0; i<T; i++)
   {
      scanf("%d\n", &arr[i]);

   }

   for(i=0; i<T; i++)
   {
      int num = arr[i];
      c=0;
      if(num == 1) {
         printf("No\n");
      } else{
         for(j=2; j<= num/2; j++)
         {

            if( num%j==0)
            {
               c=1;
               break;
            }

         }

         if(c==1)
            printf("No\n");
         else
            printf("Yes\n");

      }

   }

   return 0;
}
