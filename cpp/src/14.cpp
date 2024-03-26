#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {

    size_t longest = 0;
    if (strs.size() == 0) {
      return "";
    }

    for (size_t i = 0; i < strs[0].size(); i++) {
      for (size_t j = 1; j < strs.size(); j++) {
        if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
          return strs[0].substr(0, longest);
        }
      }
      longest++;
    }
  }
};
