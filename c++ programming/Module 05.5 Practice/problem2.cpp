#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   /*
   Time complexity O(n^2)
   Space complexity O(1)
   */
   for (int i = 0; i < n; i++) //O(n)
        for (int j = i; j > 0; j--)
            cout << i << j;

   return 0;
}

/*
Complexity,
===> Time: logn
   from line 14
   when j=i=0 , loop executes 0 time (n-1)
   when j=i=1 , loop executes 1 time (n-1)
   when j=i=2 , loop executes 2 time (n-1)
   when j=i=3 , loop executes 3 time (n-1)
   when j=i=4 , loop executes 4 time (n-1)
   ....
   when j=i=n , loop executes n-1 time

   total = O(n*(n-1)) => O(n^2 - n) = O(n^2)




*/

