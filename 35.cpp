#include <vector>

using std::vector;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {

    size_t low = 0;
    size_t high = nums.size();
    size_t mid;
    int value;

    while (low < high) {

      mid = low + (high - low) / 2;
      value = nums[mid];

      if (target == value) {
        return mid;
      } else if (target < value) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};
