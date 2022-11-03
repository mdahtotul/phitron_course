#include <stdio.h>

int main()
{
   int N, K, i;
   scanf("%d", &N);
   int roll[N];

   for(i=1;i<=N;i++){
      scanf("%d ", &roll[i]);
   }

   scanf("%d", &K);

   if(K > 0){
      for(i=K+1;i<=N;i++){
         printf("%d ", roll[i]);
      }
      for(i=1;i<=K;i++){
         printf("%d ", roll[i]);
      }
   }else if(K = 0){
      for(i=1;i<=N;i++){
         printf("%d ", roll[i]);
      }
   }

   return 0;
}
