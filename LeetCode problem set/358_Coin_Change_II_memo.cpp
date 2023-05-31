// https://leetcode.com/problems/coin-change-ii/
#include <bits/stdc++.h>
using namespace std;

const int N = 301, M = 5001;
int dp[N][M];

class Solution {
public:
    int solveMemo(vector<int>& coins,int n, int amount) {
        // base case
        if(n == 0) {
            if(amount == 0) return 1;
            return 0;
        }

        if(dp[n][amount] != -1)
            return dp[n][amount];
            
        int ans = solveMemo(coins, n-1, amount);
        for (int i = 1; i <= n; i++) {
            if(amount >= i*coins[n]) {
                ans = solveMemo(coins, n-1, amount - i * coins[n]);
                cout <<"-> " << ans << "\n";
            }
        }
        dp[n][amount] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int k = amount;
        memset(dp, -1, sizeof(dp));
        int ans = solveMemo(coins, n, amount);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
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