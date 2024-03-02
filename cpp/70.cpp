// 70. Climbing Stairs

class Solution {
public:
  int climbStairs(int n) {

    int n_2 = 0;
    int n_1 = 1;
    int n_0;

    for (int i = 0; i < n; i++) {
      n_0 = n_1 + n_2;
      n_2 = n_1;
      n_1 = n_0;
    }
    return n_1;
  }
};
