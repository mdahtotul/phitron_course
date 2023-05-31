#include <bits/stdc++.h>
using namespace std;
#define nl "\n";
typedef long long ll;

const int INF = INT_MAX;

ll n, x;

map<ll, ll> mp;
set<ll> digits(ll x) {
  // if x = 254;
  set<ll> single_digit;
  while(x) {
    single_digit.insert(x % 10);
    x /= 10;
  }

  return single_digit; // {2, 4, 5}
}

ll getLen(ll x) {
  ll len = 0;
  while(x) {
    len++;
    x /= 10;
  }
  return len;
}

ll dfs(ll src) {
  ll len = getLen(src);
  if(len == n)
    return 0;
  if(len > n)
    return INF;
  if(mp.count(src)) return mp[src];

  ll minn = INF;

  for(ll num: digits(src)) {
    if(num == 0 || num == 1)
      continue;

    minn = min(minn, 1 + dfs(src * num));
  }

  return mp[src] = minn;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  
  ll ans = dfs(x);

  if(ans == INF) {
    cout << -1 << nl;
  } else {
    cout << ans << nl;
  }

  return 0;
}