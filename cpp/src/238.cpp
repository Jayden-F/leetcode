#include <iostream>
#include <vector>

using std::vector;

class Solution
{
  public:
    vector<int>
    productExceptSelf(vector<int>& nums)
    {

        size_t n = nums.size();
        vector<int> result(n, 1);

        for(size_t i = 0; i < n - 1; i++)
        {
            result[i + 1] *= result[i] * nums[i];
        }

        int product = 1;
        for(size_t i = n - 1; i < n; i--)
        {
            result[i] *= product;
            product *= nums[i];
        }

        return result;
    }
};
