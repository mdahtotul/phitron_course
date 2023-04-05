// https://leetcode.com/problems/two-sum/

const twoSum = (nums, target) => {
  let map = {};

  for (let [index, num] of nums.entries()) {
    if (map[num] !== undefined) return [map[num], index];
    map[target - num] = index;
  }
};
