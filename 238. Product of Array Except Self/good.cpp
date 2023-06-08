#include <vector>
class Solution
{
public:
  std::vector< int > productExceptSelf(std::vector< int > &nums)
  {
    int n = nums.size();
    std::vector< int > res(n, 1);
    for (int i = 1; i < n; ++i)
    {
      res[i] = res[i - 1] * nums[i - 1];
    }
    int prodOfAllToTheRight = 1;
    for (int i = n - 1; i >= 0; --i)
    {
      res[i] *= prodOfAllToTheRight;
      prodOfAllToTheRight *= nums[i];
    }
    return res;
  }
};
