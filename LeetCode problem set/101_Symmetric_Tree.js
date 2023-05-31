class TreeNode {
  constructor(val, left, right) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

const isMirror = (left, right) => {
  if (!left || !right) return left == right;
  if (left.val === right.val)
    return isMirror(left.left, right.right) && isMirror(left.right, right.left);
};

const isSymmetric = (root) => {
  if (!root) return true;
  return isMirror(root.left, root.right) ? true : false;
};

const root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(2);
root.left.left = new TreeNode(3);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(4);
root.right.right = new TreeNode(3);

console.log(isSymmetric(root));
