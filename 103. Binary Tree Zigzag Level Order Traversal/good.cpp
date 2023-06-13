#include <vector>
#include <queue>
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode():
    val(0),
    left(nullptr),
    right(nullptr)
  {
  }
  TreeNode(int x):
    val(x),
    left(nullptr),
    right(nullptr)
  {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right):
    val(x),
    left(left),
    right(right)
  {
  }
};
class Solution
{
public:
  std::vector< std::vector< int>> zigzagLevelOrder(TreeNode *root)
  {
    std::vector< std::vector< int>> res;
    if (!root)
    {
      return res;
    }
    std::queue< TreeNode * > q;
    q.push(root);
    bool fromLeftToRight = true;
    while (!q.empty())
    {
      int size = q.size();
      std::vector< int > level(size);
      for (int i = 0; i < size; ++i)
      {
        TreeNode *node = q.front();
        q.pop();
        int index = fromLeftToRight ? i : size - i - 1;
        level[index] = node->val;
        if (node->left)
        {
          q.push(node->left);
        }
        if (node->right)
        {
          q.push(node->right);
        }
      }
      res.push_back(level);
      fromLeftToRight = !fromLeftToRight;
    }
    return res;
  }
};
