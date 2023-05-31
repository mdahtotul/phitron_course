#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0; i<n; i++) //mem O(n);
      cin>>a[i];

   for(int i=0; i<n; i++) // Time O(n)
   {
      bool sorted = true;
      cout<<i+1<<" iteration \n";
      for(int j=0; j<n-1-i; j++)
      {
         cout<<j+1<<" step \n";
         for(int i=0; i<n; i++)
            cout<<a[i]<<" ";

         cout<<"\n";
         if(a[j]>a[j+1])
         {
            swap(a[j], a[j+1]);
            sorted = false;
         }
         for(int i=0; i<n; i++)
            cout<<a[i]<<" ";

         cout<<"\n";
      }
      if(sorted) break;
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
   when i=0, loop execute n-1 time
   when i=1, loop execute n-2 time
   when i=2, loop execute n-3 time
   when i=3, loop execute n-4 time
   .......
   when i=n-1, loop execute 0 time

total => ((n-1)*n)/2; => (n^2 - n)/2;
      => n^2, after removing constant and we can ignore n. Because n^2 will take much time than n.
   So, time complexity n^2
*/
