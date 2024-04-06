#include <cstddef>

int
commonSetBits(int num);

class Solution
{
  public:
    int
    findNumber()
    {
        int result = 0;
        for(size_t i = 0; i < 32; i++)
        {
            int num = 1 << i;
            if(commonSetBits(num)) { result |= num; }
        }
        return result;
    }
};
