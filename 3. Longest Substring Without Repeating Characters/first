class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int maxLength = 0;
    int n = s.size();
    for (int j = 0; j < n; ++j)
    {
      unordered_set< char > uniqueChars;
      int c = 0;
      for (int i = j; i < n; ++i)
      {
        if (uniqueChars.count(s[i]) > 0)
        {
          break;
        }
        uniqueChars.insert(s[i]);
        c++;
      }
      maxLength = max(maxLength, c);
    }
    return maxLength;
  }
};
