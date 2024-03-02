#include <vector>

using std::vector;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    size_t k = 0;
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[k]) {
        nums[++k] = nums[i];
      }
    }
    return ++k;
  }
};
