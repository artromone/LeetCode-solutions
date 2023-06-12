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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *i1 = list1;
    ListNode *i2 = list2;
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    while (i1 && i2)
    {
      if (i1->val <= i2->val)
      {
        curr->next = i1;
        i1 = i1->next;
      }
      else
      {
        curr->next = i2;
        i2 = i2->next;
      }
      curr = curr->next;
    }
    curr->next = (i1) ? i1 : i2;
    return dummy->next;
  }
};
