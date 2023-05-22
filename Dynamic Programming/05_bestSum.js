/**
 * @Conditions
 * 1. Write a function `bestSum(targetSum, numbers)` that takes in a targetSum and an array of numbers as arguments.
 * 2. The function should return an array containing the shortest combination of numbers that add up to exactly the targetSum.
 * 3. If there is a tie for the shortest combination, you may return any one of the shortest.
 */

// brute force
/* n = amount, m = coins.length;
  time: O(m^n * n)
  space: O(n^2)
*/
const bestSum = (amount, coins) => {
  if (amount < 0) return null;
  if (amount === 0) return [];

  let shortestCombination = null;

  for (let i = 0; i < coins.length; i++) {
    const combineArr = bestSum(amount - coins[i], coins);
    if (combineArr !== null) {
      const singleCombination = [...combineArr, coins[i]];
      if (
        shortestCombination === null ||
        shortestCombination.length > singleCombination.length
      ) {
        shortestCombination = singleCombination;
      }
    }
  }

  return shortestCombination;
};

// memoization
/* n = amount, m = coins.length;
  time: O(m^2 * n)
  space: O(n^2)
*/
const bestSumMemo = (amount, coins, memo = {}) => {
  if (amount < 0) return null;
  if (amount === 0) return [];

  if (amount in memo) return memo[amount];

  let shortestCombination = null;

  for (let i = 0; i < coins.length; i++) {
    const combineArr = bestSumMemo(amount - coins[i], coins, memo);
    if (combineArr !== null) {
      const singleCombination = [...combineArr, coins[i]];
      if (
        !shortestCombination ||
        shortestCombination.length > singleCombination.length
      ) {
        shortestCombination = singleCombination;
      }
    }
  }

  memo[amount] = shortestCombination;
  return shortestCombination;
};

console.log(bestSumMemo(7, [5, 3, 4, 7])); // [7]
console.log(bestSumMemo(8, [2, 3, 5])); // [3, 5]
console.log(bestSumMemo(8, [1, 4, 5])); // [4, 4]
console.log(bestSumMemo(100, [1, 2, 5, 25])); // [25, 25, 25, 25]
