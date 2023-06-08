#include <vector>
class Solution
{
public:
  int maxSubArray(std::vector< int > &nums)
  {
    int n = nums.size();
    int maxSum = nums[0];
    int max_or_maxPlusCurr = nums[0];
    for (int i = 1; i < n; ++i)
    {
      max_or_maxPlusCurr = std::max(nums[i], nums[i] + max_or_maxPlusCurr);
      maxSum = std::max(maxSum, max_or_maxPlusCurr);
    }
    return maxSum;
  }
};
