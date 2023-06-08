#include <vector>
class Solution
{
public:
  int maxSubArray(std::vector< int > &nums)
  {
    int n = nums.size();
    int maxSum = nums[0];
    int currSum = nums[0];
    for (int i = 1; i < n; ++i)
    {
      currSum = std::max(nums[i], nums[i] + currSum);
      maxSum = std::max(maxSum, currSum);
    }
    return maxSum;
  }
};
