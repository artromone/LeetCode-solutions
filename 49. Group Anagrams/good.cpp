#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
class Solution
{
public:
  std::vector< std::vector< std::string >> groupAnagrams(std::vector< std::string > &strs)
  {
    std::unordered_map< std::string, std::vector< std::string >> map;
    for (auto &&s: strs)
    {
      std::string sorted = s;
      sort(sorted.begin(), sorted.end());
      if (map.find(sorted) == map.end())
      {
        map[sorted] = std::vector< std::string >();
      }
      map[sorted].push_back(s);
    }
    std::vector< std::vector< std::string >> res;
    for (auto &&kv: map)
    {
      res.push_back(kv.second);
    }
    return res;
  }
};
