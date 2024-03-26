#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t left = 0;
        for (size_t right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
        }
        for (size_t i = left; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};

