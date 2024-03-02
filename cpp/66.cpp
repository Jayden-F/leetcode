#include <cstdint>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
            }
            digits[i] = 0;
        }
        digits.emplace(digits.begin(), 1);
        return digits;
    }
};
