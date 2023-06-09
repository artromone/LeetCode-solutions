#include <vector>
class Solution
{
public:
  int maxArea(std::vector< int > &height)
  {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = -1;
    while (left < right)
    {
      int area = calcArea(height, left, right);
      maxArea = std::max(maxArea, area);
      if (height[left] <= height[right])
      {
        left++;
      }
      else
      {
        right--;
      }
    }
    return maxArea;
  }
private:
  int calcArea(const std::vector< int > &height, int i, int j)
  {
    return std::min(height[i], height[j]) * (j - i);
  }
};
