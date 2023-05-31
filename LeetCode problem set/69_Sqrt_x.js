// https://leetcode.com/problems/sqrtx/

const mySqrt = (x) => {
  if (x === 0) return x;
  let first = 1,
    last = x;
  while (first <= last) {
    let mid = Math.floor(first + (last - first) / 2);
    if (mid === x / mid) return mid;
    else if (mid > x / mid) last = mid - 1;
    else first = mid + 1;
  }
  return last;
};

console.log(mySqrt(8));
