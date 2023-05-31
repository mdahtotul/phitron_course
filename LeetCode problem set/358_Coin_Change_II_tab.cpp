// https://leetcode.com/problems/coin-change-ii/
#include <bits/stdc++.h>
using namespace std;

const int N = 301, M = 5001;
int dp[N][M];

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0);
        }

        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= amount; tar++) {
                int exclude = dp[i - 1][tar];
                int include = 0;
                if(coins[i] <= tar) {
                    include = dp[i][tar - coins[i]];
                }
                dp[i][tar] = exclude + include;
            }
        }

        return dp[n - 1][amount];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    Solution s;
    vector<int> coins = {2, 3, 5};
    // vector<int> coins = {2};
    int amount = 8;
    cout << s.change(amount, coins) << "\n";
    
    return 0;
}