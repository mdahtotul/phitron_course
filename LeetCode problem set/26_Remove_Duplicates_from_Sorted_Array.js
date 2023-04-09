//https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/930191919/

const removeDuplicates = (nums) => {
  let k = 0;
  for (let j = 0; j < nums.length; j++) {
    if (nums[k] !== nums[j]) {
      k++;
      nums[k] = nums[j];
    }
  }
  return k + 1;
};

console.log(removeDuplicates([1, 1, 2]));
