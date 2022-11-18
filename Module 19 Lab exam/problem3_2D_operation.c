#include <stdio.h>

int main()
{
   int N, M, i, j;
   scanf("%d %d", &N, &M);
   int a[100][100];

   for(i=1; i<=N; i++)
   {
      for(j=1; j<=M; j++)
      {
         int v;
         scanf("%d ", &v);
         if(v == i && v == j)
         {
            a[i][j] = v + 3;
         }
         else if(v == i)
         {
            a[i][j] = v + 2;
         }
         else if(v == j)
         {
            a[i][j] = v + 1;
         }
         else
         {
            a[i][j] = v;
         }

      }
   }

   for(i=1; i<=N; i++)
   {
      for(j=1; j<=M; j++)
      {
         printf("%d ", a[i][j]);
      }
      printf("\n");
   }


   return 0;
}
