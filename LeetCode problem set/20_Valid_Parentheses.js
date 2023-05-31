// https://leetcode.com/problems/valid-parentheses/

const isValid = (s) => {
  const stack = [];
  const map = {
    "(": ")",
    "{": "}",
    "[": "]",
  };

  for (let i = 0; i < s.length; i++) {
    let char = s[i];
    if (map[char]) {
      stack.push(char);
    } else {
      let sz = stack.length;
      if (sz === 0) return false;
      let last = stack[sz - 1];
      if (last === "(" && char === ")") stack.pop();
      else if (last === "{" && char === "}") stack.pop();
      else if (last === "[" && char === "]") stack.pop();
      else return false;
    }
  }
  if (stack.length === 0) return true;
  else return false;
};

console.log(isValid("(){}[]"));
