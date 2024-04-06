#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    vector<int>
    minOperations(string& boxes)
    {
        const size_t length = boxes.size();
        vector<int> result(length, 0);

        size_t cummulative_sum = 0;
        size_t count = 0;
        for(size_t i = 0; i < length; i++)
        {
            result[i] += cummulative_sum;
            count += (boxes[i] == '1');
            cummulative_sum += count;
        }

        cummulative_sum = 0;
        count = 0;
        for(size_t i = length - 1; i < length; i--)
        {
            result[i] += cummulative_sum;
            count += (boxes[i] == '1');
            cummulative_sum += count;
        }

        return result;
    }
};
