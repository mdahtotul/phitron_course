#include <stdio.h>

int main()
{
   int K, N, i, out=0;

   scanf("%d %d", &N, &K);

   int arr[N];
   for(i=1; i <= N; i++)
   {
      scanf("%d ", &arr[i]);
   }

   for(i=1; i<=N; i++)
   {
      if(arr[i] < K)
      {
         out++;
      }
   }

   printf("%d", out);

   return 0;
}
