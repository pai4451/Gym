#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int n = (int)nums.size();
    vector<int> dp(n, 0);  // dp[i] = maximum subarray sum ending at index i
    // dp[i] = max(nums[i], dp[i-1] + num[i])
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      max_sum = max(max_sum, dp[i]);
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