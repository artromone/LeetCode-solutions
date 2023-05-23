#include <string>
ListNode *split(const std::string &num)
{
  if (num.empty())
  {
    return new ListNode(0, nullptr);
  }
  ListNode *n = nullptr;
  ListNode *tail = nullptr;
  for (int i = num.size() - 1; i >= 0; --i)
  {
    ListNode *newNode = new ListNode(num[i] - '0', nullptr);
    if (n == nullptr)
    {
      n = newNode;
      tail = n;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }
  return n;
}
class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    std::string num1 = numFromList(l1);
    std::string num2 = numFromList(l2);
    std::string sum = addStrings(num1, num2);
    return split(sum);
  }
private:
  std::string numFromList(ListNode *l)
  {
    ListNode *n = l;
    std::string num;
    while (n)
    {
      num.push_back(n->val + '0');
      n = n->next;
    }
    std::reverse(num.begin(), num.end());
    return num;
  }
  std::string addStrings(const std::string &num1, const std::string &num2)
  {
    std::string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0)
    {
      int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
      int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
      int sum = digit1 + digit2 + carry;
      result.push_back(sum % 10 + '0');
      carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
