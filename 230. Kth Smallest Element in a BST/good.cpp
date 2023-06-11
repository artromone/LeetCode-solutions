#include <stack>
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
  int kthSmallest(TreeNode *root, int k)
  {
    if (root == nullptr)
    {
      return -1;
    }
    std::stack< TreeNode * > nodeStack;
    TreeNode *curr = root;
    int count = 0;
    while (curr || !nodeStack.empty())
    {
      while (curr)
      {
        nodeStack.push(curr);
        curr = curr->left;
      }
      curr = nodeStack.top();
      nodeStack.pop();
      ++count;
      if (count == k)
      {
        return curr->val;
      }
      curr = curr->right;
    }
    return -1;
  }
};
