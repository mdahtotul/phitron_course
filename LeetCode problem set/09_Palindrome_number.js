// https://leetcode.com/problems/palindrome-number/

const isPalindrome = (y) => {
  let x = y;
  let ans = 0;
  if (x < 0) return false;
  let i = 0;
  while (x > 0) {
    if (i > 0) ans = (x % 10) + ans * 10;
    else ans += x % 10;
    x = Math.floor(x / 10);
    i++;
  }
  return y === ans;
};

console.log(isPalindrome(998767889));
