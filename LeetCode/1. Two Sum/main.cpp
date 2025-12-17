/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time
complexity?
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;  // value -> index
    for (size_t i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      auto it = map.find(complement);
      if (it != map.end()) {
        return {it->second, (int)i};  // Return stored index, not distance
      }
      map[nums[i]] = i;
    }
    return {};  // No solution found
  }
};

int main() {
  Solution s;
  vector<vector<int>> nums = {{2, 7, 11, 15}, {3, 2, 4}, {3, 3}};

  vector<int> targets = {9, 6, 6};

  for (int i = 0; i < targets.size(); i++) {
    vector<int> num = nums[i];
    int target = targets[i];
    auto ans = s.twoSum(num, target);
    cout << "Answer: ";
    for (int x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}