#include <algorithm>
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
  int maxPathSum(TreeNode *root)
  {
    int maxSum = INT_MIN;
    maxPathSum_impl(root, maxSum);
    return maxSum;
  }
private:
  int maxPathSum_impl(TreeNode *root, int &maxSum)
  {
    if (!root)
    {
      return 0;
    }
    int nodeSum = root->val;
    int leftSum = std::max(0, maxPathSum_impl(root->left, maxSum));
    int rightSum = std::max(0, maxPathSum_impl(root->right, maxSum));
    int pathSum = nodeSum + leftSum + rightSum;
    maxSum = std::max(maxSum, pathSum);
    return nodeSum + std::max(leftSum, rightSum);
  }
};
