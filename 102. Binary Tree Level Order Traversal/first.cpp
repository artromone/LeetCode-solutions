#include <algorithm>
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
  std::vector< std::vector< int >> levelOrder(TreeNode *root)
  {
    int h = determineH(root);
    std::vector< std::vector< int >> res(h, std::vector< int >());
    lo_impl(root, 0, res);
    return res;
  }
public:
  void lo_impl(TreeNode *root, int level, std::vector< std::vector< int >> &res)
  {
    if (!root)
    {
      return;
    }
    res[level].push_back(root->val);
    lo_impl(root->left, level + 1, res);
    lo_impl(root->right, level + 1, res);
  }
  int determineH(TreeNode *root)
  {
    if (!root)
    {
      return 0;
    }
    return std::max(determineH(root->left), determineH(root->right)) + 1;
  }
};
