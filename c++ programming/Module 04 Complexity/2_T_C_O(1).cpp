#include <bits/stdc++.h>

using namespace std;

/*
Time complexity O(1);
Memory complexity O(1);
*/

int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int maxx = max({a,b,c});
   int minn = min({a,b,c});
   int summ = a+b+c;
   int multi = a*b*c;

   cout<<maxx<<"\n";
   cout<<minn<<"\n";
   cout<<summ<<"\n";
   cout<<multi<<"\n";
}
