#include <vector>
#include <algorithm>
class Solution
{
public:
  std::vector< std::vector< int >> merge(std::vector< std::vector< int >> &intervals)
  {
    std::vector< std::vector< int >> res = {};
    Comp comp;
    sort(intervals.begin(), intervals.end(), comp);
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i)
    {
      if (intervals[i][0] <= res.back()[1])
      {
        res.back()[1] = std::max(intervals[i][1], res.back()[1]);
      }
      else
      {
        res.push_back(intervals[i]);
      }
    }
    return res;
  }
private:
  struct Comp
  {
    bool operator()(const std::vector< int > &lhs, const std::vector< int > &rhs) const
    {
      return lhs[0] < rhs[0];
    }
  };
};
