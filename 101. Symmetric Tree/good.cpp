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
  bool isSymmetric(TreeNode *root)
  {
    return isMirror(root->left, root->right);
  }
private:
  bool isMirror(TreeNode *r1, TreeNode *r2)
  {
    if (!r1 && !r2)
    {
      return true;
    }
    if (!r1 || !r2)
    {
      return false;
    }
    bool isLeftMirror = isMirror(r1->left, r2->right);
    bool isRightMirror = isMirror(r1->right, r2->left);
    bool areDataIdent = (r1->val == r2->val);
    return isLeftMirror && areDataIdent && isRightMirror;
  }
};
