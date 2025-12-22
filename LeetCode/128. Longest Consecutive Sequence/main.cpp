/*
Given an unsorted array of integers nums, return the length of the longest
consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4. Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Time Limit Exceeded
// 75 / 84 testcases passed
// Last Executed Input
// Use Testcase
// nums =
// [-1000000000,1,2,3,9,1000000000]
// class Solution {
//  public:
//   int longestConsecutive(vector<int>& nums) {
//     if (nums.size() == 0){
//         return 0;
//     }
//     int maximum = *max_element(nums.begin(), nums.end());
//     int minimum = *min_element(nums.begin(), nums.end());
//     vector<bool> vec(maximum - minimum + 1, false);
//     for (int& num : nums) {
//       vec[num - minimum] = true;
//     }
//     int bestConsecutive = 0;
//     int bestStart = 0;
//     int bestEnd = 0;
//     bool started = false;
//     for (int i = 0; i < vec.size(); i++) {
//       if (vec[i] && !started) {
//         // started, we need to set start and end
//         bestStart = i;
//         bestEnd = i;
//         started = true;
//       } else if (vec[i] && started) {
//         // already started, simply update end
//         bestEnd = i;
//       } else {
//         // not started, or stop previous consecutive, reset started to false
//         started = false;
//       }
//       bestConsecutive = max(bestConsecutive, bestEnd - bestStart + 1);
//     }
//     return bestConsecutive;
//   }
// };

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());  // 去重 + O(1)查找(期望)
    int best = 0;
    for (int x : s) {
      if (s.find(x - 1) == s.end()) {  // x is start
        int len = 1;
        int next = x + 1;
        while (s.find(next) != s.end()) {
          next++;
          len++;
        }
        best = max(best, len);
      }
    }
    return best;
  }
};

int main() {
  Solution s;
  vector<vector<int>> nums{
      {100, 4, 200, 1, 3, 2}, {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, {1, 0, 1, 2}};

  for (auto& num : nums) {
    cout << s.longestConsecutive(num) << endl;
  }
  return 0;
}