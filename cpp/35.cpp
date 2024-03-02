#include <vector>

using std::vector;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {

    size_t low = 0;
    size_t high = nums.size();

    while (low < high) {

      size_t mid = low + (high - low) / 2;
      const int &value = nums[mid];

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
