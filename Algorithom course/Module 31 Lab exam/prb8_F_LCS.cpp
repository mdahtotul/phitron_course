// https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
using namespace std;
#define nl "\n";

const int N = 3001;
int dp[N][N];
int n, m;
int choice[N][N];

string s, t, ansStr;

// axcb, abyxb

int LCS(int i, int j) {
  if(i < 0 || j < 0) {
    return 0;
  }

  if(dp[i][j] != -1)
    return dp[i][j];

  int ans = 0;
  if(s[i] == t[j]) {
    ans = 1 + LCS(i - 1, j - 1);
  } else {
    ans = max(LCS(i - 1, j), LCS(i, j - 1));
  }

  return dp[i][j] = ans;
}

string printLCS(int i, int j) {
  if(i < 0 || j < 0)
    return "";
  
  if(s[i] == t[j])
    return printLCS(i - 1, j - 1) + s[i];
  if(dp[i-1][j] > dp[i][j-1])
    return printLCS(i - 1, j);

  return printLCS(i, j - 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s >> t;
  n = s.size() - 1, m = t.size() - 1;

  memset(dp, -1, sizeof(dp));

  int len = LCS(n, m);
  cout << printLCS(n, m) << nl;

  return 0;
}