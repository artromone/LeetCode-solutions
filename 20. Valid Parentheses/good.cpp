#include <stack>
#include <string>
#include <unordered_map>
class Solution
{
public:
  bool isValid(std::string s)
  {
    std::unordered_map< char, char > map = {{')', '('}, {'}', '{'}, {']', '['}};
    std::stack< char > stack;
    for (char c: s)
    {
      if (c == '(' || c == '[' || c == '{')
      {
        stack.push(c);
      }
      if (c == ')' || c == ']' || c == '}')
      {
        if (stack.empty() || stack.top() != map[c])
        {
          return false;
        }
        stack.pop();
      }
    }
    return stack.empty();
  }
};
