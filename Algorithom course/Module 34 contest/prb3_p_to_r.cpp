#include <iostream>
using namespace std;
#define nl '\n';
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t;
  cin>>t;

  while(t--) {
    ll l, r;
    cin >> l >> r;

    if(l > r)
      swap(l, r);

    ll sum1 = (r * (r + 1)) / 2;
    ll sum2 = (l * (l + 1)) / 2;

    cout << sum1 - sum2 + l << nl;
  }
  return 0;
}

/*
Input:
4
3 6
2 11
4 16
17 7
Output:
*/