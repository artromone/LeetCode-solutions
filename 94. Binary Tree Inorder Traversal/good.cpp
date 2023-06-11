#include <vector>
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode():
    val(0), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x):
    val(x), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right):
    val(x), left(left), right(right)
  {
  }
};
class Solution
{
public:
  std::vector< int > inorderTraversal(TreeNode *root)
  {
    std::vector< int > res = {};
    inorderTraversalHelper(root, res);
    return res;
  }
public:
  void inorderTraversalHelper(TreeNode *root, std::vector< int > &res)
  {
    if (!root)
    {
      return;
    }
    inorderTraversalHelper(root->left, res);
    res.push_back(root->val);
    inorderTraversalHelper(root->right, res);
  }
};
