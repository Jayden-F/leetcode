#include <vector>

using std::vector;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    size_t nums1_size = nums1.size();
    size_t nums2_size = nums2.size();
    size_t total_size = nums1_size + nums2_size;
    size_t median = total_size / 2;
    size_t nums1_idx = 0;
    size_t nums2_idx = 0;

    for (size_t i = 0; i < median; i++) {
      if (nums1_idx >= nums1_size) {
        nums2_idx++;
      } else if (nums2_idx >= nums2_size) {
        nums1_idx++;
      } else if (nums1[nums1_idx] < nums2[nums2_idx]) {
        nums1_idx++;
      } else {
        nums2_idx++;
      }
    }
  }
};
