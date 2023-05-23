class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x >= 0)
    {
      if (x < 10)
      {
        return true; 
      }
      std::string sx = std::to_string(x);
      int n = sx.size();
      for (int i = 0; i < n / 2; ++i)
      {
        if (sx[i] != sx[n - i - 1])
        {
          return false;
        }
      }
      return true;
    }
    return false;
  }
};
