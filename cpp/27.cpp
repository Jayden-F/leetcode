#include <vector>

using std::vector;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {

    size_t k = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[k++] = nums[i];
      }
    }
    return k;
  }
};
