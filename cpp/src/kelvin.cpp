#include <cstdint>
#include <string>

bool perm_is_palidrome(std::string str) {
  uint32_t bit_set = 0;

  for (char c : str) {
    bit_set ^= 1 << c - 'a';
  }

  return !(bit_set & bit_set - 1);
}
