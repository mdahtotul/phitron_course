// https://leetcode.com/problems/plus-one/
const plusOne = (digits) => {
  let idx = digits.length - 1;
  for (let i = 0; i < digits.length; i++) {
    if (digits[idx] === 9) {
      digits[idx] = 0;
      idx--;
    } else {
      digits[idx]++;
      return digits;
    }
  }
  digits.unshift(1);
  return digits;
};

const data = plusOne([3, 9, 9]);
data.forEach((item) => console.log(item));
