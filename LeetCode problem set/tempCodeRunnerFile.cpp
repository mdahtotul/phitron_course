or (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int exclude = dp[i - 1][j];
                int include = 0;
                if(coins[i] <= j) {
                    include = dp[i][j - coins[i]];
                }
                dp[i][j] = exclude + include;
            }
        }