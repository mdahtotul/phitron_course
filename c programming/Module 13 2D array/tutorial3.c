#include <stdio.h>

int main()
{
   int row=4, col=3, i, j;
   int a[row][col];

   for(i=0; i<row; i++)
   {
      for(j=0; j<col; j++)
      {
         scanf("%d ", &a[i][j]);
      }
   }

   for(i=0; i<row; i++)
   {
      for(j=0; j<col; j++)
      {
         printf("%d     ", a[i][j]);
      }
      printf("\n");
   }

   return 0;
}
