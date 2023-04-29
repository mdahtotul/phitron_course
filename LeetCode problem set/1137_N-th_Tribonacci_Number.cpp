#include <bits/stdc++.h>
using namespace std;

const int N = 45;

long long dp[N];

class Solution {
public:
    long long tribonacci(long long n) {
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i <= n; i++) {
          dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     long long tribonacci(long long n) {
//         if(n == 0)
//             return 0;
//         else if(n == 1 || n == 2)
//             return 1;
//         else if(n == 3)
//             return 2;

//         if(dp[n] > 0) {
//             return dp[n];
//         }

//         return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
//     }
// };

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  Solution sol;
  int n;
  cin >> n;
  cout << sol.tribonacci(n) << "\n";
  return 0;
}