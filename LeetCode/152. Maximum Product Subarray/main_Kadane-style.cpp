#include <algorithm>
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
    int max_so_far = nums[0];  // max_so_far = 「所有『一定要以 nums[i] 結尾』的
                               // subarray 裡，乘積最大的那一個」
    int min_so_far = nums[0];  // min_so_far = 「所有『一定要以 nums[i] 結尾』的
                               // subarray 裡，乘積最小的那一個」
    int best_product = nums[0];
    for (int i = 1; i < n; i++) {
      int prev_max = max_so_far;
      int prev_min = min_so_far;
      max_so_far = max({nums[i], prev_max * nums[i], prev_min * nums[i]});
      min_so_far = min({nums[i], prev_max * nums[i], prev_min * nums[i]});
      best_product = max(best_product, max_so_far);
    }
    return best_product;
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