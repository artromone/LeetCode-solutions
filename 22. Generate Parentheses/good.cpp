#include <string>
#include <vector>
class Solution
{
public:
  std::vector< std::string > generateParenthesis(int n)
  {
    std::string curr = "";
    std::vector< std::string > res = {};
    backtrack(res, curr, 0, 0, n);
    return res;
  }
private:
  void backtrack(std::vector< std::string > &res, std::string curr, int open, int close, int n)
  {
    if (curr.length() == 2 * n)
    {
      res.push_back(curr);
      return;
    }
    if (open < n)
    {
      curr.push_back('(');
      backtrack(res, curr, open + 1, close, n);
      curr.pop_back();
    }
    if (close < open)
    {
      curr.push_back(')');
      backtrack(res, curr, open, close + 1, n);
      curr.pop_back();
    }
  }
};