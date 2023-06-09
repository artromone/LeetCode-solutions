#include <vector>
class Solution
{
public:
  std::vector< int > countBits(int n)
  {
    std::vector< int > ans(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      int countBitsInHalfOfI = ans[i >> 1];
      int leastSignificantBit = (i & 1);
      ans[i] = countBitsInHalfOfI + leastSignificantBit;
    }
    return ans;
  }
};
