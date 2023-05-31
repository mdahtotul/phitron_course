#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];


   for(int i=1; i<n; i++)
   {
      int idx = i;
      while(idx>=1)
      {
         if(a[idx-1] > a[idx])
         {
            swap(a[idx -1], a[idx]);
            idx--;
         }
         else
         {
            break;
         }
      }
   }

      for(int i=0; i<n; i++)
         cout<<a[i]<<" ";

   return 0;
}

/*
Complexity
   Time: O(n^2)
   Memory: O(n)
*/

/*
in line 13
   when n=i, loop execute 1 time
   when n=i+1, loop execute 2 time
   when n=i+2, loop execute 3 time
   when n=i+3, loop execute 4 time
   .......
   when n=i+last_index, loop execute n-1 time

total => ((n-1)*n); => (n^2 - n);
      => n^2, after removing constant and we can ignore n. Because n^2 will take much time than n.
   So, time complexity n^2
*/
