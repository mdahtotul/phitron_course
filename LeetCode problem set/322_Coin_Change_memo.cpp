// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveMemo(vector<int>& coins, vector<int>& dp, int amount) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        int n = coins.size();

        if(dp[amount] != -1) return dp[amount];

        int minCoins = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = solveMemo(coins, dp, amount - coins[i]);

            if(ans != INT_MAX)
                minCoins = min(minCoins, ans + 1);
        }
        dp[amount] = minCoins;
        return minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);

        int ans = solveMemo(coins, dp, amount);
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