#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;
   /*
      Time complexity O(n^3)
      Space complexity O(1)
   */
   for (int i = 0; i < n; i++)
        for (int j = i; j > 0; j--)
            for(int k=j; k > 0; k--)
                cout << i << j << k;

   return 0;
}
