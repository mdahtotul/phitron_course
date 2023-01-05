#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    /*
       Time complexity O(nlogn)
       Space complexity O(1)
    */
    for(int i=1; i<=n; i++) // O(n)
    {


        if(__builtin_popcount(i) == 1)
        {
            for(int j=1; j<=n; j++)
                cout<<"i => "<<i<<" j => "<<j<<endl;
        }
    }

    return 0;
}

/*



*/
