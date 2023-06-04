#include <unordered_map>
#include <vector>
class Solution
{
public:
  std::vector< int > twoSum(std::vector< int > &nums, int target)
  {
    std::unordered_map< int, int > map = {};
    for (int i = 0; i < nums.size(); ++i)
    {
      int findFor = target - nums[i];
      if (map.find(findFor) == map.end())
      {
        map[nums[i]] = i;
      }
      else
      {
        return {map[findFor], i};
      }
    }
    return {};
  }
};
