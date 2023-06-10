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
  bool isValidBST(TreeNode *root)
  {
    if (!root)
    {
      return true;
    }
    bool leftLess = true;
    if (root->left)
    {
      leftLess = (root->left->val < root->val);
    }
    bool rightGreat = true;
    if (root->right)
    {
      rightGreat = (root->right->val > root->val);
    }
    bool closestChildsValid = isValidBST(root->left) && isValidBST(root->right);
    bool allChildsValid = closestChildsValid && isSubtreeLess(root->left, root->val) && isSubtreeGreater(root->right, root->val);
    return (leftLess && rightGreat && allChildsValid);
  }
private:
  bool isSubtreeLess(TreeNode *node, int value)
  {
    if (!node)
    {
      return true;
    }
    if (node->val < value)
    {
      return isSubtreeLess(node->left, value) && isSubtreeLess(node->right, value);
    }
    return false;
  }
  bool isSubtreeGreater(TreeNode *node, int value)
  {
    if (!node)
    {
      return true;
    }
    if (node->val > value)
    {
      return isSubtreeGreater(node->left, value) && isSubtreeGreater(node->right, value);
    }
    return false;
  }
};
