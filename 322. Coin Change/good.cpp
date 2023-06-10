#include <vector>
class Solution
{
public:
  int coinChange(std::vector< int > &coins, int amount)
  {
    std::vector< int > dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (auto i = 1; i < amount + 1; ++i)
    {
      for (auto coin: coins)
      {
        if (i - coin < 0)
        {
          continue;
        }
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
      }
    }
    return (dp[amount] != amount + 1) ? dp[amount] : -1;
  }
};
