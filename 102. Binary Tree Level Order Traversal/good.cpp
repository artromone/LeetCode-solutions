#include <vector>
#include <queue>
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
std::vector< std::vector< int >> levelOrder(TreeNode *root)
{
  std::vector< std::vector< int >> result;
  if (root == nullptr)
  {
    return result;
  }
  std::queue< TreeNode * > q;
  q.push(root);
  while (!q.empty())
  {
    int levelSize = q.size();
    std::vector< int > levelNodes;
    for (int i = 0; i < levelSize; i++)
    {
      TreeNode *node = q.front();
      q.pop();
      levelNodes.push_back(node->val);
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }
    result.push_back(levelNodes);
  }
  return result;
}
