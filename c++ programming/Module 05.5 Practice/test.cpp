#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n / 2);

    /* step 2 */
    cout << n % 2;
}

int main()
{
    int n;
    cin>>n;
    /*
       Time complexity O(n^3)
       Space complexity O(1)
    */
    for(int i=1; i<=n; i++)
    {

       cout<<"Binary";
       bin(i);
       cout<<"\n";
       cout<<i<<" popcount "<<__builtin_popcount(i);

       cout<<"\n\n";
//        if(__builtin_popcount(i) == 1)
//        {
//            for(int j=1; j<=n; j++)
//                cout<<"i => "<<i<<" j => "<<j<<endl;
//        }
    }

    return 0;
}

/*



*/
