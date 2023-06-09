#include <algorithm>
#include <vector>
class Solution
{
public:
  std::vector< std::vector< int>> threeSum(std::vector< int > &nums)
  {
    std::sort(nums.begin(), nums.end());
    std::vector< std::vector< int>> res = {};
    int n = nums.size();
    for (auto i = 0; i < n - 2; ++i)
    {
      if (i > 0)
      {
        if (nums[i] == nums[i - 1])
        {
          continue;
        }
      }
      int left = i + 1;
      int right = n - 1;
      while (left < right)
      {
        int currSum = nums[left] + nums[i] + nums[right];
        if (currSum > 0)
        {
          right--;
        }
        else if (currSum < 0)
        {
          left++;
        }
        else
        {
          res.push_back({nums[left], nums[i], nums[right]});
          while (left < right && nums[left] == nums[left + 1])
          {
            ++left;
          }
          while (left < right && nums[right] == nums[right - 1])
          {
            --right;
          }
          ++left;
          --right;
        }
      }
    }
    return res;
  }
};
