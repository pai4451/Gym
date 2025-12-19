#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = (int)prices.size();
    int min_price = INT_MAX;  // minPrice：目前看過的最低價格（最便宜的買點）
    int max_profit = 0;
    for (int i = 0; i < n; i++) {
      if (prices[i] < min_price) {
        min_price = prices[i];  // 把今天當可能更好的買入日
      }
      max_profit = max(max_profit, prices[i] - min_price);  // 今天賣
    }
    return max_profit;
  }
};

int main() {
  vector<vector<int>> nums = {{7, 1, 5, 3, 6, 4}, {7, 6, 4, 3, 1}};
  Solution s;
  for (auto& num : nums) {
    int profit = s.maxProfit(num);
    cout << "Max profit is: " << profit << endl;
  }

  return 0;
}