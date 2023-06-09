#include <vector>
int missingNumber(std::vector< int > &nums)
{
  int n = nums.size();
  int total = (n * (n + 1)) / 2;
  for (int num: nums)
  {
    total -= num;
  }
  return total;
}
