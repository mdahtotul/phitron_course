#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    /*
       Time complexity O(logn*logn) => O((logn)^2)
       Space complexity O(1)
    */
    int o_l = 1;
    for(int i=n/2; i<=n; i++) // logn because it starts from half of n
    {
        cout<<"Outer loop : "<<i<<"\n";
        cout<<"Inner loop"<<" : ";
        for(int j=1; j<=n; j=j*2) //logn because it will increase the prev value by 2 times
        {
            //cout<<i<<j<<endl;
            cout<<j<<" ";

        }
        o_l++;
        cout<<"\n";
    }

    return 0;
}
