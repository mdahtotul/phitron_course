/**
 * @conditions
 * 1. Write a function `howSum(amount, coins)` that takes in a amount and an array of numbers as arguments.
 * 2. The function should return an array containing any combination of elements that add up to exactly the amount. If there is no combination that adds up to the amount, then return null.
 * 3. If there are multiple combinations possible, you may return any single one.
 */

// brute force
const howSum = (amount, coins) => {
  if (amount < 0) return null;
  if (amount === 0) return [];

  const n = coins.length;
  for (let i = 0; i < n; i++) {
    const combineArr = howSum(amount - coins[i], coins);
    if (combineArr !== null) {
      return [...combineArr, coins[i]];
    }
  }
  return null;
};

// memoization
const howSumMemo = (amount, coins, memo = {}) => {
  if (amount < 0) return null;
  if (amount === 0) return [];

  if (amount in memo) return memo[amount];

  const n = coins.length;
  for (let i = 0; i < n; i++) {
    const combineCoins = howSumMemo(amount - coins[i], coins, memo);
    if (combineCoins !== null) {
      memo[amount] = [...combineCoins, coins[i]];
      return memo[amount];
    }
  }
  memo[amount] = null;
  return null;
};

console.log(howSumMemo(7, [2, 3])); // [3, 2, 2]
console.log(howSumMemo(7, [5, 3, 4, 7])); // [4, 3]
console.log(howSumMemo(7, [2, 4])); // null
console.log(howSumMemo(8, [2, 3, 5])); // [2, 2, 2, 2]
console.log(howSumMemo(300, [7, 14])); // null
