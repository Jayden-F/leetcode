#include <string>
#include <algorithm>

using std::string;
using std::stringstream;

class Solution {
public:
  string addBinary(string a, string b) {
    int carry_bit = 0;
    string solution;

    int i = a.length() - 1;
    int j = b.length() - 1;


    while( i >= 0 || j >= 0 || carry_bit) {
        carry_bit += i >= 0 ? a[i--] - '0' : 0;
        carry_bit += j >= 0 ? b[j--] - '0' : 0;
        solution += carry_bit % 2 + '0';
        carry_bit /= 2;
    }


    std::reverse(solution.begin(), solution.end());
    return solution;
  }
};
