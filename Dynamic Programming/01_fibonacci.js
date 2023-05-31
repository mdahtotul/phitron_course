// brute force
const fib = (n) => {
  if (n === 0) return 0;
  if (n <= 1) return 1;

  return fib(n - 1) + fib(n - 2);
};

// console.log(fib(50));

// memoization
const fibMemo = (n, memo = {}) => {
  if (n === 0) return 0;
  if (n <= 1) return 1;

  if (n in memo) return memo[n];

  memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
  return memo[n];
};

console.log(fibMemo(50));

// tabulation
const fibTab = (n, dp = {}) => {
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;

  for (let i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
};

console.log(fibTab(50));

/*
  Brute Force: O(2^n) time | O(n) space
  Memoization: O(n) time | O(n) space
  Tabulation: O(n) time | O(n) space
*/
