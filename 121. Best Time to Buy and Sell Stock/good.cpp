#include <vector>
class Solution
{
public:
  int maxProfit(std::vector< int > &prices)
  {
    int minPrice = 100001;
    int maxDiff = 0;
    for (auto &&price: prices)
    {
      minPrice = std::min(minPrice, price);
      int potDiff = price - minPrice;
      maxDiff = std::max(potDiff, maxDiff);
    }
    return maxDiff;
  }
};