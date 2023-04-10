// https://leetcode.com/problems/climbing-stairs/

const climbStairs = (n) => {
  let ways = 1,
    prv = 1,
    i = 1;
  while (i < n) {
    ways += prv;
    prv = ways - prv;
    i++;
  }
  return ways;
};

console.log(climbStairs(5));
