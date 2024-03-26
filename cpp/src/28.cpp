#include <map>
#include <string>

using std::string;

class Solution {
public:
  int strStr(string haystack, string needle) {

    size_t haystack_len = haystack.size();
    size_t needle_len = needle.size();

    std::map<char, int> bad_char_table{};
    for (int i = 0; i < needle.size(); i++) {
      bad_char_table[needle.at(i)] = i;
    }

    return -1;
  }
};
