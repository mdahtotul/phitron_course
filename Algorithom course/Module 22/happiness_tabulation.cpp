// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

/*
- state: fun(n) -> max happiness of till day-n, if we pick task-x on n-th day

- recurrence: fun(n, x) = max {
                                fun(n-1, y) + h[n][x] // where x != y
                              }

- base case: fun(1, x) = h[1][x]
*/

int hpy[N][4], dp[N][4];

int fun(int day, int cur_task) {

  for (int task = 1; task <= 3; task++)
    dp[1][task] = hpy[1][task];

  for (int day = 1; day <= n; day++) {
    
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> hpy[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  int ans_1 = fun(n, 1);
  int ans_2 = fun(n, 2);
  int ans_3 = fun(n, 3);

  cout << max({ans_1, ans_2, ans_3}) << "\n";
  return 0;
}