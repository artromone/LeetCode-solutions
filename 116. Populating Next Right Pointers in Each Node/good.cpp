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
    Node *curr = root;
    while (curr->left)
    {
      Node *levelRunner = curr;
      while (levelRunner)
      {
        levelRunner->left->next = levelRunner->right;
        if (levelRunner->next)
        {
          levelRunner->right->next = levelRunner->next->left;
        }
        levelRunner = levelRunner->next;
      }
      curr = curr->left;
    }
    return root;
  }
};
