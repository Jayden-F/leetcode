#include <cstdint>
#include <string>

using std::string;

// Type your code here, or load an example.
bool
canPermutePalindrome(const string& str)
{
    uint32_t bit_set = 0;

    for(char c : str)
    {
        bit_set ^= 1 << (c - 'a');
    }

    return !(bit_set & bit_set - 1);
}
