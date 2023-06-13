#include <vector>
class Solution
{
public:
  int missingNumber(std::vector< int > &nums)
  {
    int n = nums.size();
    int XOR_total = 0;
    int XOR_nums = 0;
    for (int i = 0; i <= n; ++i)
    {
      XOR_total ^= i;
    }
    for (int num: nums)
    {
      XOR_nums ^= num;
    }
    return XOR_total ^ XOR_nums; // All numbers except the missing one occur twice
  }
};
