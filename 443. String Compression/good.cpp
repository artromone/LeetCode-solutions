#include <vector>
#include <string>
class Solution
{
public:
  int compress(std::vector< char > &chars)
  {
    int n = chars.size();
    int index = 0;
    int count = 1;
    for (int i = 1; i <= n; ++i)
    {
      if (i < n && chars[i] == chars[i - 1])
      {
        count++;
      }
      else
      {
        chars[index++] = chars[i - 1];
        if (count > 1)
        {
          std::string str = std::to_string(count);
          for (char c: str)
          {
            chars[index++] = c;
          }
        }
        count = 1;
      }
    }
    return index;
  }
};
