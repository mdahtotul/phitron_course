#include <bits/stdc++.h>

using namespace std;

int main()
{
   int a=4, b=5, c=7, d=2, e=100;
   swap(a,b);
   cout<<a<<" "<<b<<endl;

   int minn = min(a,b);
   cout<<minn<<endl;
   int maxx = max(a,b);
   cout<<maxx<<endl;

   int min_arr = min({a,b,c,d});
   cout<<min_arr<<endl;
   int max_arr = max({a,b,c,d,e});
   cout<<max_arr<<endl;

//   vector<int>a = {3,4,5,1,7,2,6};
//
//   for(int i=0; i<a.size(); i++)
//      cout<<a[i]<<" ";
//
//   cout<<endl;
//
//   sort(a.begin(), a.end());
//   cout<<"After sorting"<<endl;
//   for(int i=0; i<a.size(); i++)
//      cout<<a[i]<<" ";
//   cout<<endl;

   return 0;
}
