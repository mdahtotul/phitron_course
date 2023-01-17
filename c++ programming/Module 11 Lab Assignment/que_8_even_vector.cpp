#include <bits/stdc++.h>
using namespace std;

vector<int> even_generator(vector<int> arr)
{
   vector<int> newArr;
   for(int i=0; i<arr.size(); i++)
   {
      if(arr[i]%2==0)
         newArr.push_back(arr[i]);
   }
   return newArr;
}

int main()
{
   vector<int> a = {1,6,3,4,5};

   vector<int> ans = even_generator(a);

   for(int i=0; i<ans.size(); i++)
      cout<<ans[i]<<" ";
   return 0;
}
