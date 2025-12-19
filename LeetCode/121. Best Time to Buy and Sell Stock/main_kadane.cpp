#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = (int)prices.size();
    int cur = 0, ans = 0;
    for (int i = 1; i < n; i++) {
      int diff = prices[i] - prices[i - 1];
      cur = max(
          0, cur + diff);  // 最大獲利（允許不交易）而非最大子陣列和（允許負數）
      ans = max(ans, cur);
    }
    return ans;
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