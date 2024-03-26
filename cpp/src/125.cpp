#include <string>

using std::string;
class Solution {
public:
  bool isPalindrome(string s) {

    size_t low = 0;
    size_t high = s.size();

    while (low < high) {
      if (s[low++] != s[--high]) {
        return false;
      }
    }
    return true;
  }
};
