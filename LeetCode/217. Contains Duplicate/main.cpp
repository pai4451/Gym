/*
Given an integer array nums, return true if any value appears at least twice in
the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true
*/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto& num : nums) {
      if (s.count(num)) {  // If already exists, found duplicate
        return true;
      }
      s.insert(num);
    }
    return false;
  }
};

int main() {
  vector<vector<int>> nums = {
      {1, 2, 3, 1}, {1, 2, 3, 4}, {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}};
  Solution s;

  cout << boolalpha;
  for (auto& num : nums) {
    auto ans = s.containsDuplicate(num);
    cout << ans << endl;
  }

  return 0;
}