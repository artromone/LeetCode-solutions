#include <iostream>
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):
    val(x), left(nullptr), right(nullptr)
  {
  }
};
class Codec
{
public:
  std::string serialize(TreeNode *root)
  {
    if (root == nullptr)
    {
      return "";
    }
    return std::to_string(root->val) + "(" + serialize(root->left) + ")(" + serialize(root->right) + ")";
  }
  TreeNode *deserialize(std::string data)
  {
    int index = 0;
    return deserializeHelper(data, index);
  }
private:
  TreeNode *deserializeHelper(const std::string &data, int &index)
  {
    if (index >= data.length())
    {
      return nullptr;
    }
    if (data[index] == '(')
    {
      index++;
    }
    if (data[index] == ')')
    {
      index++;
      return nullptr;
    }
    int value = 0;
    while (index < data.length() && isdigit(data[index]))
    {
      value = value * 10 + (data[index] - '0');
      index++;
    }
    TreeNode *node = new TreeNode(value);
    node->left = deserializeHelper(data, index);
    node->right = deserializeHelper(data, index);
    return node;
  }
};
