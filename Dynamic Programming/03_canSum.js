/**
 * @Conditions
 * 1. Write a function `canSum(amount, coins)` that takes in a amount and an array of coins as arguments.
 * 2. The function should return a boolean indicating whether or not it is possible to generate the amount using coins from the array.
 * 3. You may use an element from the array as many times as needed.
 * 4. You may assume that all input numbers are nonnegative.
 */

// brute force
const canSum = (coins, amount) => {
  if (amount < 0) return false;
  if (amount === 0) return true;

  for (let i = 0; i < coins.length; i++) {
    let reminder = amount - coins[i];
    if (canSum(coins, reminder) === true) {
      return true;
    }
  }

  return false;
};

// memoization
const canSumMemo = (coins, amount, memo = {}) => {
  if (amount < 0) return false;
  if (amount === 0) return true;

  if (amount in memo) return memo[amount];

  for (let i = 0; i < coins.length; i++) {
    const reminder = amount - coins[i];
    let val = canSumMemo(coins, reminder, memo);
    memo[reminder] = val;
    if (val === true) return true;
  }

  return false;
};

// tabulation
const canSumTab = (coins, amount, dp = {}) => {
  dp["0, 0"] = 1;

  for (let j = 0; j < coins.length; j++) {
    dp[`${coins[j]}, 0`] = 1;
  }
  for (let i = 1; i <= amount; i++) {
    let ans = 0;
    if (i % coins[0] === 0) {
      ans = 1;
    }
    dp[`${coins[0]}, ${i}`] = ans;
  }

  for (let i = 1; i < coins.length; i++) {
    for (let j = 0; j <= amount; j++) {
      let exclude = dp[`${coins[i - 1]}, ${j}`];
      let include = 0;
      if (coins[i] <= j) {
        include = dp[`${coins[i]}, ${j - coins[i]}`];
      }
      dp[`${coins[i]}, ${j}`] = include + exclude;
    }
  }

  // for (key in dp) {
  //   console.log("(coin, target) = ", key, " isPossible = ", dp[key]);
  // }

  let ans = false;
  for (let i = 0; i < coins.length; i++) {
    if (dp[`${coins[i]}, ${amount}`] > 0) {
      ans = true;
      break;
    }
  }
  return ans;
};

console.log(canSumTab([2, 3], 7)); // true
console.log(canSumTab([5, 3, 4, 7], 7)); // true
console.log(canSumTab([2, 4], 7)); // false
console.log(canSumTab([2, 3, 5], 8)); // true
console.log(canSumTab([7, 14], 300)); // false
