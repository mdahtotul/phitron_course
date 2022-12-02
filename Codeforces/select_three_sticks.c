// codeforces problem 1734/A
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[], int n);
void swap(int *x, int *y);
int minn(int a, int b, int c);

int main()
{
   int t, i, j;
   scanf("%d", &t);

   while(t--)
   {
      int n;
      scanf("%d", &n);
      int a[n];
      for(j=0; j<n; j++)
      {
         scanf("%d ", &a[j]);
      }
      bubble_sort(a, n);

      int ans;

      for(i=2; i<n; i++)
      {
         int x=a[i-2], y=a[i-1], z=a[i];
         int ans1, ans2, ans3;

         ans1 = abs(x-x) + abs(y-x) + abs(z-x);
         ans2 = abs(x-y) + abs(y-y) + abs(z-y);
         ans3 = abs(x-z) + abs(y-z) + abs(z-z);

         ans = minn(ans1, ans2, ans3);
         printf("Ans = %d\n", ans);
      }
   }
   return 0;
}

void bubble_sort(int a[], int n)
{
   int p,q;
   for(p=0; p<n-1; p++)
   {
      for(q=p; q<n; q++)
      {
         if(a[p] > a[q])
         {
            swap(&a[p], &a[q]);
         }
      }
   }
}

void swap(int *x, int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int minn(int a, int b, int c)
{
   if(a<b && a<c)
      return a;
   else if(b<a && b<c)
      return b;
   else if(c<a && c<b)
      return c;
}
