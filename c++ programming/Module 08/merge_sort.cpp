#include <bits/stdc++.h>

using namespace std;

vector<int> merge_sort(vector<int>a)
{
   // base case
   int len = a.size();
   if(len<=1)
      return a;

   // Dividing step
   int mid = len/2;
   vector<int>b;
   vector<int>c;
   for(int i=0; i<mid; i++)
      b.push_back(a[i]);
   for(int i=mid; i<len; i++)
      c.push_back(a[i]);

   vector<int>sorted_b = merge_sort(b);
   vector<int>sorted_c = merge_sort(c);

   // Conquer step
   vector<int>sorted_a;
   int idxB = 0, idxC = 0;
   for(int i=0; i<len; i++)
   {
      if(idxB == sorted_b.size())
      {
         sorted_a.push_back(sorted_c[idxC]);
         idxC++;
      }
      else if(idxC == sorted_c.size())
      {
         sorted_a.push_back(sorted_b[idxB]);
         idxB++;
      }
      else if(sorted_b[idxB] < sorted_c[idxC])
      {
         sorted_a.push_back(sorted_b[idxB]);
         idxB++;
      }
      else
      {
         sorted_a.push_back(sorted_c[idxC]);
         idxC++;
      }
   }
   return sorted_a;
}

int main()
{
   vector<int>a = {5,3,7,8,4,6};
   vector<int>ans = merge_sort(a);

   for(int i=0; i<a.size(); i++)
      cout<<ans[i]<<" ";

   return 0;
}
