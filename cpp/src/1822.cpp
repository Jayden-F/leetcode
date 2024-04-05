#include <vector>

using std::vector;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool sign = 0;
        for (int num : nums) {
            if (!num) {
                return 0;
            }
            else{
            sign ^= (num >> 31) & 1;
            }
        }
        return sign ? -1 : 1;
    }
};

