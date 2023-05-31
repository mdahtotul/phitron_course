#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    /*
       Time complexity O(n.logn)
       Space complexity O(1)
    */
    for(int i=n/2; i<=n; i++) //O(logn)
    {
        for(int j=1; j<=n; j=j+i)//O(n)
        {
            cout<<i<<j<<endl;
        }
    }

    return 0;
}

