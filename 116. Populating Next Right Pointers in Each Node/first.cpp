class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node():
    val(0),
    left(nullptr),
    right(nullptr),
    next(nullptr)
  {
  }
  Node(int _val):
    val(_val),
    left(nullptr),
    right(nullptr),
    next(nullptr)
  {
  }
  Node(int _val, Node *_left, Node *_right, Node *_next):
    val(_val),
    left(_left),
    right(_right),
    next(_next)
  {
  }
};
class Solution
{
public:
  Node *connect(Node *root)
  {
    if (!root)
    {
      return nullptr;
    }
    connect_impl(root->left, root->right);
    return root;
  }
private:
  void connect_impl(Node *node1, Node *node2)
  {
    if (!node1 || !node2)
    {
      return;
    }
    node1->next = node2;
    connect_impl(node1->left, node1->right);
    connect_impl(node2->left, node2->right);
    connect_impl(node1->right, node2->left);
  }
};
