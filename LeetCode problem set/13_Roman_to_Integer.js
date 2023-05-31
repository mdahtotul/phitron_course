// https://leetcode.com/problems/roman-to-integer/

const romanVal = {
  I: 1,
  V: 5,
  X: 10,
  L: 50,
  C: 100,
  D: 500,
  M: 1000,
};

const romanToInt = (s) => {
  let count = 0;

  for (let i = 0; i < s.length; i++) {
    let cur = s[i];
    let next = s[i + 1];
    if (romanVal[cur] < romanVal[next]) {
      count -= romanVal[cur];
    } else {
      count += romanVal[cur];
    }
  }
  return count;
};

let roman = romanToInt("LVIII");
console.log("🚀 ~ file: 13_Roman_to_Integer.js:29 ~ romanToInt:", roman);
