#include <iostream>
class Solution
{
public:
  std::uint32_t reverseBits(std::uint32_t n)
  {
    std::uint32_t reversed = 0;
    int bits = 32;
    while (bits--)
    {
      reversed <<= 1;
      reversed |= (n & 1);
      n >>= 1;
    }
    return reversed;
  }
};
