#include <stdio.h>

int main()
{
   int row, col, i, j;
   printf("Provide row and col: ");

   int a[row][col];
   printf("Provide matrix value: ");

   for(i=0; i<row; i++)
   {
      for(j=0; j<col; j++)
      {
         scanf("%d ", &a[i][j]);
      }
   }

   int ans = 1;
   int x = a[0][0];
   if(row==col)
   {
      if(a[])
      {

         continue;
      }
      if(a[i][j] != 0)
      {
         ans = 0;
      }
   }
   else
   {
      printf("Row & Col are not same");
   }

   return 0;
}
