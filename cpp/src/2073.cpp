#include <cstddef>
#include <vector>

using std::vector;

class Solution
{
  public:
    int
    timeRequiredToBuy(vector<int>& tickets, int k)
    {
        int elapsed_time = tickets[k];

        for(size_t i = 0; i < k; i++)
        {
            elapsed_time += std::min(tickets[k], tickets[i]);
        }

        for(size_t i = k + 1; i < tickets.size(); i++)
        {
            elapsed_time += std::min(tickets[k] - 1, tickets[i]);
        }

        return elapsed_time;
    }
};
