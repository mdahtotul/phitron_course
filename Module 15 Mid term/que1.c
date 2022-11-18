#include <stdio.h>

int main()
{
   int n = 10;
   int x = 5;
   int index = 0;
   int a[] = {12, 7, 3, 71, 2, 43, 38, 23, 45, 22};
   int b[n];
   for (int i=0; i<n; i++) {
      b[i] = a[i] + x;
   }

   return 0;
}
