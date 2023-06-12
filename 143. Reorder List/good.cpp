struct ListNode
{
  int val;
  ListNode *next;
  ListNode():
    val(0),
    next(nullptr)
  {
  }
  ListNode(int x):
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
  void reorderList(ListNode *head)
  {
    if (!head || !head->next || !head->next->next)
    {
      return;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *prev = nullptr;
    ListNode *curr = slow->next;
    slow->next = nullptr;
    while (curr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    ListNode *first = head;
    ListNode *second = prev;
    while (second)
    {
      ListNode *firstNext = first->next;
      ListNode *secondNext = second->next;
      first->next = second;
      second->next = firstNext;
      first = firstNext;
      second = secondNext;
    }
  }
};
