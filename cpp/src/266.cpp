#include <cstdint>
#include <string>

using std::string;

// Type your code here, or load an example.
bool canPermutePalindrome(const string &str) {
  uint32_t bit_set = 0;
  const size_t length = str.size();

  // Toggle the bit for each character to determine an even or uneven number of
  // appearances.
  for (size_t i = 0; i < length; i++) {
    bit_set ^= 1 << (str[i] - 'a');
  }

  // If the length is uneven, there can only be one character that appears
  // uneven amount of times. Meaning we check if the bit set is a power of 2.
  // If the length is even, there can't be any characters that appear an uneven
  // so we check if the bit set is 0.
  return ((length & 1) && !(bit_set & bit_set - 1)) ||
         (!(length & 1) && !bit_set);
}
