#include <cstdint>
#include <vector>

using std::vector;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int index_1 = m - 1;
    int index_2 = n - 1;
    int index_merged = n + m - 1;

    while (index_1 >= 0 && index_2 >= 0) {
      if (nums1[index_1] > nums2[index_2]) {
        nums1[index_merged] = nums1[index_1];
        index_1--;
      } else {
        nums1[index_merged] = nums2[index_2];
        index_2--;
      }
      index_merged--;
    }
    for (; index_2 >= 0; index_2--, index_merged--) {
      nums1[index_merged] = nums2[index_2];
    }
  }
};
