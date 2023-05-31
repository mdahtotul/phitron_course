/**
 * @Conditions
 * 1. Write a function `canConstruct(target, wordBank)` that accepts a target string and an array of strings.
 * 2. The function should return a boolean indicating whether or not the `target` can be constructed by concatenating elements of the `wordBank` array.
 * 3. You may reuse elements of `wordBank` as many times as needed.
 */

// brute force
/**
 * n = target.length
 * m = wordBank.length
 * O(n^m * m)
 */

const canConstruct = (target, wordBank) => {
  if (!target) return true;

  for (let word of wordBank) {
    // O(n^m)
    if (target.indexOf(word) === 0) {
      // O(m)
      const suffix = target.slice(word.length);
      if (canConstruct(suffix, wordBank)) {
        return true;
      }
    }
  }
  return false;
};

const canConstructMemo = (target, wordBank, memo = {}) => {
  if (!target) return true;
  if (target in memo) return memo[target];

  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      if (canConstructMemo(suffix, wordBank, memo)) {
      }
    }
  }
  return false;
};

console.log(canConstructMemo("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // true
console.log(
  canConstructMemo("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])
); // false
console.log(
  canConstructMemo("enterapotentpot", [
    "a",
    "p",
    "ent",
    "enter",
    "ot",
    "o",
    "t",
  ])
); // true
console.log(
  canConstructMemo("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
    "eeeeee",
  ])
); // false
