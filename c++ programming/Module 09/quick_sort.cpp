#include <bits/stdc++.h>
using namespace std;

vector<int> quick_sort(vector<int>a)
{
   int len = a.size();
   if(len <= 1)
      return a;

   int pivot = rand()%(a.size()); // selecting random element as pivot which will
   vector<int> b,c;

   for(int i=0; i<len; i++) //O(n)
   {
      if(i==pivot)
         continue;

      if(a[i] <= a[pivot])
         b.push_back(a[i]);
      else
         c.push_back(a[i]);
   }

   vector<int>sorted_b = quick_sort(b);
   vector<int>sorted_c = quick_sort(c);
   vector<int>sorted_a;

   for(int i=0; i<sorted_b.size(); i++) // from line 28 to 34 complexity O(n)
      sorted_a.push_back(sorted_b[i]);

   sorted_a.push_back(a[pivot]);
   for(int i=0; i<sorted_c.size(); i++)
      sorted_a.push_back(sorted_c[i]);

   return sorted_a;
}

int main()
{
   vector<int>a = {5,3,7,8,4,6};
   vector<int>ans = quick_sort(a);

   for(int i=0; i<a.size(); i++)
      cout<<ans[i]<<" ";
   return 0;
}
