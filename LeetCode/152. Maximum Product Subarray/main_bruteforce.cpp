#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int n = nums.size();
    int bestProduct = nums[0];
    for (int i = 0; i < n; i++) {
      int accumulate = 1;
      for (int j = i; j < n; j++) {
        accumulate = accumulate * nums[j];
        bestProduct = max(bestProduct, accumulate);
      }
    }
    return bestProduct;
  }
};

int main() {
  Solution s;
  vector<vector<int>> nums{{2, 3, -2, 4}, {-2, 0, -1}, {0, 2}};
  for (auto& num : nums) {
    cout << s.maxProduct(num) << endl;
  }
  return 0;
}