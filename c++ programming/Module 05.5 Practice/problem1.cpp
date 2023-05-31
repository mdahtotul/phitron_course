#include <bits/stdc++.h>

using namespace std;

/*
   Time complexity O(logn);
   Space complexity O(1);
*/

int main()
{
   int n;
   cin>>n
    int k=1;
    while(k<=n)
    {
        cout<<k<<endl;
        k=k*2;
    }

    return 0;
}

/*
Complexity,
===> Time: logn
   condition k=k*2;
   when k=1 & n=10, loop executes 1st time
   when k=2 & n=10, loop executes 2nd time
   when k=4 & n=10, loop executes 3rd time
   when k=8 & n=10, loop executes 4th time


*/
