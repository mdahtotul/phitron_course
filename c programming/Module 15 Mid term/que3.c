#include <stdio.h>
// Geometric progression


int main()
{
   int i, n=15;
   int a[15];

   a[0] = 1;
   for(i=1; i<n; i++)
   {

      a[i] = a[i-1]*2;
   }

   for(i=0; i<n; i++)
   {

      printf("%d ", a[i]);
   }
   return 0;
}

