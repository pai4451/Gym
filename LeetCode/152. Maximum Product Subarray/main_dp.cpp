#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp_max(n);  // maximum product ending at nums[i]
    vector<int> dp_min(n);  // minimum product ending at nums[i]
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    int bestProduct = nums[0];
    for (int i = 1; i < n; i++) {
      dp_max[i] =
          max({nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]});
      dp_min[i] =
          min({nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]});
      bestProduct = max(bestProduct, dp_max[i]);
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