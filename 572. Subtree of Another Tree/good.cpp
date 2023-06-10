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
class Solution
{
public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    if (!root)
    {
      return false;
    }
    if (areEqual(root, subRoot))
    {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
private:
  bool areEqual(TreeNode *root1, TreeNode *root2)
  {
    if (!root1 && !root2)
    {
      return true;
    }
    if (!root1 || !root2)
    {
      return false;
    }
    bool leftEqual = areEqual(root1->left, root2->left);
    bool rightEqual = areEqual(root1->right, root2->right);
    bool valEqual = (root1->val == root2->val);
    return leftEqual && rightEqual && valEqual;
  }
};
