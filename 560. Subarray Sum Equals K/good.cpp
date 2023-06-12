#include <vector>
#include <unordered_map>
class Solution
{
public:
  int subarraySum(std::vector< int > &nums, int k)
  {
    std::unordered_map< int, int > map = {{0, 1}};
    int currSum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      currSum += nums[i];
      int target = currSum - k;
      if (map.count(target))
      {
        res += map[target];
      }
      map[currSum]++;
    }
    return res;
  }
};
