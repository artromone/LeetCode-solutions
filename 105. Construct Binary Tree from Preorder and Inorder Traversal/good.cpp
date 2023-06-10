#include <vector>
#include <algorithm>
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
  TreeNode *buildTree(std::vector< int > &preorder, std::vector< int > &inorder)
  {
    if (preorder.empty())
    {
      return nullptr;
    }
    int rootValue = preorder[0];
    auto rootInorderIter = std::find(inorder.begin(), inorder.end(), rootValue);
    int leftSubtreeSize = std::distance(inorder.begin(), rootInorderIter);
    //int rightSubtreeSize = inorder.size() - 1 - leftSubtreeSize;

    TreeNode *root = new TreeNode(rootValue);

    auto leftPreorder = std::vector< int >(preorder.begin() + 1, preorder.begin() + 1 + leftSubtreeSize);
    auto leftInorder = std::vector< int >(inorder.begin(), inorder.begin() + leftSubtreeSize);
    root->left = buildTree(leftPreorder, leftInorder);

    auto rightPreorder = std::vector< int >(preorder.begin() + 1 + leftSubtreeSize, preorder.end());
    auto rightInorder = std::vector< int >(inorder.begin() + 1 + leftSubtreeSize, inorder.end());
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
  }
};
