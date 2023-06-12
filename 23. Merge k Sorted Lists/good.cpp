#include <vector>
#include <queue>
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
  ListNode *mergeKLists(std::vector< ListNode * > &lists)
  {
    //auto compNodes = std::bind(std::less<ListNode*>(), _1, _2);
    std::priority_queue< ListNode *, std::vector< ListNode * >, CompNodes > map;
    for (ListNode *head: lists)
    {
      if (head)
      {
        map.push(head);
      }
    }
    ListNode *dummy = new ListNode();
    ListNode *prev = dummy;
    while (!map.empty())
    {
      ListNode *curr = map.top();
      map.pop();
      prev->next = curr;
      prev = prev->next;
      if (curr->next)
      {
        map.push(curr->next);
      }
    }
    return dummy->next;
  }
private:
  struct CompNodes
  {
    bool operator()(const ListNode *lhs, const ListNode *rhs)
    {
      return lhs->val > rhs->val;
    }
  };
};
