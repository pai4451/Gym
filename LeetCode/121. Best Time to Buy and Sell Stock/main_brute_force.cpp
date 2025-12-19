#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int max_profix = 0;
    int n = (int)prices.size();
    for (int i = 0; i < n; i++) {
      int profit = 0;
      for (int j = i + 1; j < n; j++) {
        profit = prices[j] - prices[i];
        max_profix = profit > max_profix ? profit : max_profix;
      }
    }
    return max_profix;
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