#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    return maxSubArrayDC(nums, 0, nums.size() - 1);
  }

 private:
  int crossMaxSubArray(vector<int>& nums, int left, int mid, int right) {
    int sum = 0;
    int leftBest = nums[mid];
    for (int i = mid; i >= left; --i) {
      sum += nums[i];
      leftBest = max(leftBest, sum);
    }

    int rightBest = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
      sum += nums[i];
      rightBest = max(rightBest, sum);
    }

    return leftBest + rightBest;
  }

  int maxSubArrayDC(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];

    int mid = left + (right - left) / 2;
    int leftMax = maxSubArrayDC(nums, left, mid);
    int rightMax = maxSubArrayDC(nums, mid + 1, right);
    int crossMax = crossMaxSubArray(nums, left, mid, right);
    return max({leftMax, rightMax, crossMax});
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