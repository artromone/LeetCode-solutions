#include <string>
#include <vector>
class Solution
{
public:
  std::vector< std::string > summaryRanges(std::vector< int > &nums)
  {
    std::vector< std::string > res = {};
    int n = nums.size();
    if (n == 0)
    {
      return res;
    }
    int start = nums[0];
    int end = nums[0];
    for (int i = 1; i < n; ++i)
    {
      if (nums[i] == nums[i - 1] + 1)
      {
        end = nums[i];
      }
      else
      {
        addToRes(res, start, end);
        start = nums[i];
        end = nums[i];
      }
    }
    addToRes(res, start, end);
    return res;
  }
private:
  void addToRes(std::vector< std::string > &res, int a, int b)
  {
    std::string s = (a != b) ? std::to_string(a) + "->" + std::to_string(b) : std::to_string(a);
    res.push_back(s);
  }
};