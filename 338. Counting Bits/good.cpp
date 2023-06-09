#include <vector>
#include <iostream>
class Solution
{
public:
  std::vector< int > countBits(int n)
  {
    std::vector< int > res = {};
    for (auto i = 0; i <= n; ++i)
    {
      res.push_back(hammingWeight(i));
    }
    return res;
  }
private:
  int hammingWeight(std::uint32_t n)
  {
    int count = 0;
    while (n > 0)
    {
      count += (n & 1);
      n >>= 1;
    }
    return count;
  }
};