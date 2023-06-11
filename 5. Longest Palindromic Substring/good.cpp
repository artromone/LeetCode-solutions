#include <string>
class Solution
{
public:
  std::string longestPalindrome(std::string s)
  {
    if (s.empty())
    {
      return "";
    }
    int start = 0;
    int maxLen = 1;
    for (int i = 0; i < s.length(); ++i)
    {
      int oddLen = expandFromCenter(s, i, i);
      int evenLen = expandFromCenter(s, i, i + 1);
      int len = std::max(oddLen, evenLen);
      if (len > maxLen)
      {
        start = i - (len - 1) / 2;
        maxLen = len;
      }
    }
    return s.substr(start, maxLen);
  }
private:
  int expandFromCenter(const std::string &s, int left, int right)
  {
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
      left--;
      right++;
    }
    return right - left - 1;
  }
};