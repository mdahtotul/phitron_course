// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
const strStr = (haystack, needle) => {
  if (needle.length > haystack.length) return -1;
  let len = haystack.length - needle.length + 1;
  for (let i = 0; i < len; i++) {
    for (let j = 0; j < needle.length; j++) {
      if (needle[j] !== haystack[j + i]) break;
      else if (j === needle.length - 1) return i;
    }
  }
  return -1;
};

console.log(strStr("hello", "ll"));
