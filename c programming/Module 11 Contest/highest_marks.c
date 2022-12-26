#include <stdio.h>

int main()
{
   int N, i, max;
   scanf("%d", &N);

   int arr[N];
   for(i=0; i<N; i++)
   {
      scanf("%d ", &arr[i]);
   }

   max=arr[0];
   for(i=0; i<N; i++)
   {
      if(arr[i]> max){
         max= arr[i];
      }
   }

   for(i=0; i<N; i++)
   {
      printf("%d ", max - arr[i]);
   }

   return 0;
}
