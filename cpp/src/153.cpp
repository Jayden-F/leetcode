#include <vector>

using std::vector;

class Solution {
  int findMin(vector<int> &nums) {

    size_t low = 0;
    size_t high = nums.size() - 1;

    while (low < high) {
      size_t mid = low + (high - low) / 2;
      if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};
