#include <algorithm>
#include <vector>
class Solution
{
public:
  void moveZeroes(std::vector< int > &nums)
  {
    std::stable_partition(nums.begin(), nums.end(), ZeroComparator());
  }
private:
  struct ZeroComparator
  {
    bool operator()(int num) const
    {
      return num != 0;
    }
  };
};
