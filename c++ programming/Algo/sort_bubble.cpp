#include <bits/stdc++.h>
using namespace std;

vector<int> bubble_sort(vector<int>a)
{
   int len = a.size();

   for(int i=0; i<len; i++)
   {
      for(int j=0; j<len-i; j++)
      {
         if(a[j] > a[j+1])
            swap(a[j], a[j+1]);
      }
   }

   return a;
}

int main()
{
   vector<int> arr = {3,5,4,6,2,7};

   vector<int> ans = bubble_sort(arr);

   for(int i=0; i<ans.size(); i++)
      cout<<ans[i]<<" ";
   return 0;
}
