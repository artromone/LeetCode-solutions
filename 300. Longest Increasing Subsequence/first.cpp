#include <vector>
#include <algorithm>
class Solution
{
public:
  int lengthOfLIS(std::vector< int > &nums)
  {
    int n = nums.size();
    std::vector< int > LIS(n, 1);
    for (int i = n - 2; i >= 0; --i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        if (nums[i] >= nums[j])
        {
          continue;
        }
        LIS[i] = std::max(LIS[i], LIS[j] + 1);
      }
    }
    return *std::max_element(LIS.begin(), LIS.end());
  }
};
