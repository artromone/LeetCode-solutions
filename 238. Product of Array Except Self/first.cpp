#include <vector>
class Solution
{
public:
  std::vector< int > productExceptSelf(std::vector< int > &nums)
  {
    int n = nums.size();
    std::vector< int > left(n, 1);
    std::vector< int > right(n, 1);
    for (auto i = 1; i < n; ++i)
    {
      left[i] = left[i - 1] * nums[i - 1];
    }
    for (auto i = n - 2; i >= 0; --i)
    {
      right[i] = right[i + 1] * nums[i + 1];
    }
    std::vector< int > res = {};
    for (auto i = 0; i < n; ++i)
    {
      res.push_back(left[i] * right[i]);
    }
    return res;
  }
};