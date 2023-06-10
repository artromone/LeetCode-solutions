#include <vector>
class Solution
{
public:
  int climbStairs(int n)
  {
    std::vector< int > memory(n + 1, -1);
    return climbStairsHelper(0, n, memory);
  }
private:
  int climbStairsHelper(int a, int b, std::vector< int > &memory)
  {
    if (a > b)
    {
      return 0;
    }
    else if (a == b)
    {
      return 1;
    }
    else if (memory[a] != -1)
    {
      return memory[a];
    }
    else
    {
      memory[a] = climbStairsHelper(a + 1, b, memory) + climbStairsHelper(a + 2, b, memory);
      return memory[a];
    }
  }
};
