#include <vector>
#include <algorithm>
class Solution
{
public:
  int longestOnes(std::vector< int > &nums, int k)
  {
    int res = 0;
    int left = 0;
    int zCount = 0;
    for (int right = 0; right < nums.size(); ++right)
    {
      if (nums[right] == 0)
      {
        zCount++;
      }
      while (zCount > k)
      {
        if (nums[left] == 0)
        {
          zCount--;
        }
        left++;
      }
      res = std::max(res, right - left + 1);
    }
    return res;
  }
};
