#include <stdint.h>

class Solution {
public:
  int hammingWeight(uint32_t n) {
    uint32_t result = 0;
    for (uint32_t i = 0; i < 32; i++) {
      result += n >> i & 1;
    }
    return result;
  }
};
