// https://leetcode.com/problems/longest-common-prefix/

const longestCommonPrefix = (arr = []) => {
  let ans = "";
  let n = arr.length;
  if (n == 0) return ans;
  arr.sort((a, b) => {
    if (a > b) return 1;
    else if (a < b) return -1;
    else return 1;
  });

  let first = arr[0];
  let last = arr[n - 1];
  let len = Math.min(first.length, last.length);
  for (let i = 0; i < len; i++) {
    if (first[i] != last[i]) {
      return ans;
    }
    ans += first[i];
  }
  return ans;
};

console.log(longestCommonPrefix(["abab", "aba", "abc"]));
