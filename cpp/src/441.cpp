class Solution {
public:
  int arrangeCoins(int n) {

    int low = 0;  // inclusive
    int high = n; // inclusive

    while (low < high) {
      int mid = low + (high - low) / 2;
      double half_mid = mid / 2.0;
      int total_coins = half_mid * (mid + 1);

      if (total_coins == n) {
        return mid;
      } else if (total_coins < n) {
        low = mid;
      } else {
        high = mid;
      }
    }
    return high;
  }
};
