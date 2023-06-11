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
  std::vector< std::vector< int >> zigzagLevelOrder(TreeNode *root)
  {
    int n = maxTreeDepth(root);
    std::vector< std::vector< int >> res(n, std::vector< int >());
    int level = 0;
    zLOHelper(root, res, level);
    return res;
  }
private:
  void zLOHelper(TreeNode *root, std::vector< std::vector< int >> &res, int level)
  {
    if (!root)
    {
      return;
    }
    if (level % 2 == 0)
    {
      res[level].push_back(root->val);
    }
    else
    {
      res[level].insert(res[level].begin(), root->val);
    }
    zLOHelper(root->left, res, level + 1);
    zLOHelper(root->right, res, level + 1);
  }
  int maxTreeDepth(TreeNode *root)
  {
    if (!root)
    {
      return 0;
    }
    return 1 + std::max(maxTreeDepth(root->left), maxTreeDepth(root->right));
  }
};
