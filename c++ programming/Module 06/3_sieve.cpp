#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   vector<int>primes;
   vector<bool>visited(n+1);

   for(int i=2; i<=n; i++) // time O(n)
   {
      if(!visited[i])
      {
         primes.push_back(i);
         for(int x=2; i*x<=n; x++) // time nlogn
            visited[i*x] = true;
      }
   }

   for(int i=0; i<primes.size(); i++)
      cout<<primes[i]<<" ";

   cout<<"\n";

   return 0;
}

/*
Complexity
   Time: O(n^2)
   Memory: O(n)
*/

/*
in line 17
   when i=2, loop execute n/2 time
   when i=3, loop execute n/3 time
   when i=4, loop execute 0 time for the sack of simplicity let's think it n/4
   when i=5, loop execute n/5 time
   when i=6, loop execute 0 time for the sack of simplicity let's think it n/6
   .......
   SO, n/2 + n/3 + n/4 + n/5 + n/6 + ......+ n/n
   =>  n(1/2 + 1/3 + 1/4 +1/5 +1/6 + ......+ 1/n)
   =>  n(1 +1/2 +1/3 +1/4 +1/5 +1/6 + ......+ 1/n) NOTE: 1 +1/2 +1/3 +1/4 +1/5 +1/6 + ......+ 1/n = ln(n) = loge(n)
   => n(logn)

total => ((n-1)*n); => (n^2 - n);
      => n^2, after removing constant and we can ignore n. Because n^2 will take much time than n.
   So, time complexity n^2
*/
