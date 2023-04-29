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
  // 1. handle base case
  if (day == 1) {
    return hpy[day][cur_task];
  }

  // 2. if ans is already calculated, return it
  if(dp[day][cur_task] != -1)
    return dp[day][cur_task];

  // 3. calculate ans
  int ans = 0;
  for (int l_task = 1; l_task <= 3; l_task++) {
    if (l_task != cur_task) {
      int new_ans = fun(day - 1, l_task) + hpy[day][cur_task];
      ans = max(ans, new_ans);
    }
  }
  dp[day][cur_task] = ans;
  return ans;
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