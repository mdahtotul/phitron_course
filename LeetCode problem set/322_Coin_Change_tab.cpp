// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveTab(vector<int>& coins, vector<int>& dp, int amount) {
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++){
            for (int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX )
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);

        int ans = solveTab(coins, dp, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << s.coinChange(coins, amount) << "\n";
    return 0;
}