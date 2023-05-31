#include <bits/stdc++.h>
using namespace std;

int sum_rec(int n) {
  if(n == 0) return 0;
  return n % 10 + sum_rec(n / 10);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  int ans = 0;
  ans = sum_rec(n);
  cout << ans << "\n";
  return 0;
}