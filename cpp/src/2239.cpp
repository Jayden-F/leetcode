#include <vector>

using std::vector;

class Solution {
public:
  int findClosestNumber(vector<int> &nums) {

    size_t closest_index = 0;

    for (size_t i = 1; i < nums.size(); i++) {
      int difference = abs(nums[i]) - abs(nums[closest_index]);
      if (difference < 0) {
        closest_index = i;
      } else if (difference == 0) {
        closest_index = nums[i] > 0 ? i : closest_index;
      }

    }
    return nums[closest_index];
  }
};
