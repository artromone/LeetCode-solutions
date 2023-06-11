#include <vector>
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
  TreeNode *sortedArrayToBST(std::vector< int > &nums)
  {
    return buildBSTHelper(nums, 0, nums.size() - 1);
  }
private:
  TreeNode *buildBSTHelper(std::vector< int > &nums, int left, int right)
  {
    if (left > right)
    {
      return nullptr;
    }
    int middle = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[middle]);
    root->left = buildBSTHelper(nums, left, middle - 1);
    root->right = buildBSTHelper(nums, middle + 1, right);
    return root;
  }
};
