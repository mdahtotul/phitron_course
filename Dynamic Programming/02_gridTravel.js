/**
 * @Conditions
 * 1. You are located at the top-left corner of a [m x n] grid
 * 2. You can only move either down or right at any point in time
 * 3. You have to go to the bottom-right corner of the grid
 * 4. How many possible unique paths are there?
 */
// brute force
const gridTravel = (row, col) => {
  if (row < 1 || col < 1) return 0;
  if (row === 1 && col === 1) return 1;

  return gridTravel(row - 1, col) + gridTravel(row, col - 1);
};

// memoization
const gridTravelMemo = (row, col, memo = {}) => {
  const key = row + ", " + col;
  if (row < 1 || col < 1) return 0;
  if (row === 1 && col === 1) return 1;

  if (key in memo) return memo[key];

  memo[key] =
    gridTravelMemo(row - 1, col, memo) + gridTravelMemo(row, col - 1, memo);

  return memo[key];
};

console.log(gridTravelMemo(18, 18));

// tabulation
const gridTravelTab = (row, col, dp = {}) => {
  dp["1, 1"] = 1;

  for (let i = 1; i <= row; i++) {
    dp[`${i}, 1`] = 1;
  }
  for (let j = 1; j <= col; j++) {
    dp[`1, ${j}`] = 1;
  }

  for (let i = 2; i <= row; i++) {
    for (let j = 2; j <= col; j++) {
      dp[`${i}, ${j}`] = dp[`${i - 1}, ${j}`] + dp[`${i}, ${j - 1}`];
    }
  }

  return dp[`${row}, ${col}`];
};

console.log(gridTravelTab(18, 18));
