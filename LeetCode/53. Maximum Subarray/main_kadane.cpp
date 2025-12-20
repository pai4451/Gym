#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = (int)nums.size();
    int current_sum = nums[0];
    int max_sum = nums[0];
    for (int i = 1; i < n; i++) {
      current_sum = max(current_sum + nums[i], nums[i]); // current_sum = 以 i 結尾的最大子陣列和（至少包含 nums[i]）
      max_sum = max(max_sum, current_sum);
    }
    return max_sum;
  }
};

int main() {
  Solution s;
  vector<vector<int>> nums = {
      {-2, 1, -3, 4, -1, 2, 1, -5, 4}, {1}, {5, 4, -1, 7, 8}};
  for (auto& num : nums) {
    cout << s.maxSubArray(num) << endl;
  }
  return 0;
}