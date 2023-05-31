#include <bits/stdc++.h>

using namespace std;

void beauty_permu(int n)
{
    if(n==2 || n==3)
        cout<<"NO SOLUTION";
    else if (n==1)
        cout<<1;
    else
    {
        if(n%2==0)
        {
            for(int i=2; i<=n; i+=2)
                cout<<i<<" ";
            for(int i=1; i<=n-1; i+=2)
                cout<<i<<" ";
        }
        else
        {
            for(int i=2; i<=n-1; i+=2)
                cout<<i<<" ";
            for(int i=1; i<=n; i+=2)
                cout<<i<<" ";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int n;
    cin>>n;

    beauty_permu(n);

    return 0;
}
