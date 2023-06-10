struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode():
    val(0), left(nullptr), right(nullptr)
  {}
  TreeNode(int x):
    val(x), left(nullptr), right(nullptr)
  {}
  TreeNode(int x, TreeNode *left, TreeNode *right):
    val(x), left(left), right(right)
  {}
};
bool isValidBSTHelper(TreeNode *node, long long minVal, long long maxVal)
{
  if (!node)
  {
    return true;
  }
  if (node->val <= minVal || node->val >= maxVal)
  {
    return false;
  }
  return isValidBSTHelper(node->left, minVal, node->val)
         && isValidBSTHelper(node->right, node->val, maxVal);
}
bool isValidBST(TreeNode *root)
{
  return isValidBSTHelper(root, 0, 10001);
}
