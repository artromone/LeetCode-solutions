struct ListNode
{
  int val;
  ListNode *next;
  ListNode():
    val(0),
    next(nullptr)
  {
  }
  explicit ListNode(int x):
    val(x),
    next(nullptr)
  {
  }
  ListNode(int x, ListNode *next):
    val(x),
    next(next)
  {
  }
};
class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    while (l1 || l2)
    {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      if (tail)
      {
        if (tail->next)
        {
          sum += tail->next->val;
          delete tail->next;
          tail->next = nullptr;
        }
      }
      if (sum < 10)
      {
        insertDigit(&head, &tail, new ListNode(sum, nullptr));
      }
      else
      {
        ListNode *dozen = new ListNode(1, nullptr);
        insertDigit(&head, &tail, new ListNode(sum - 10, dozen));
      }
      l1 = (l1) ? l1->next : l1;
      l2 = (l2) ? l2->next : l2;
    }
    return head;
  }
private:
  void insertDigit(ListNode **head, ListNode **tail, ListNode *insert)
  {
    if (*head != nullptr)
    {
      (*tail)->next = insert;
      *tail = insert;
    }
    else
    {
      *head = insert;
      *tail = insert;
    }
  }
};
