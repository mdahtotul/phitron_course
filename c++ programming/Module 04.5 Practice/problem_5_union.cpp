#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    int m;
    cin>>m;
    vector<int>b(m);
    for(int i=0; i<m; i++)
        cin>>b[i];

   //sort(a.begin(), a.end());
   //sort(b.begin(), b.end());

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";


    for(int y=0; y<m; y++)
    {
       int f = 0;
        for(int x=0; x<n; x++)
        {
            if(a[x] == b[y])
            {
               f = 1;
               break;
            }
        }
        f == 0 && cout<<b[y]<<" ";

    }
    return 0;
}
