#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v= {2,9,1,3,7};

    sort(v.begin()+1,v.begin()+3);

    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << '\n';
    return 0;
}
