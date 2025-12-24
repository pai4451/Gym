#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// // O(n^3), TLE
// class Solution {
//  public:
//   vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<vector<int>> ans;
//     unordered_set<string> s;

//     for (int i = 0; i < nums.size(); i++) {
//       for (int j = i + 1; j < nums.size(); j++) {
//         for (int k = j + 1; k < nums.size(); k++) {
//           if (nums[i] + nums[j] + nums[k] == 0) {
//             // how to deduplicate vector?
//             // unordered_set element can be vector? No, only if we provide
//             // custom hash function

//             vector<int> t = {nums[i], nums[j], nums[k]};
//             sort(t.begin(), t.end());
//             string key =
//                 to_string(t[0]) + "," + to_string(t[1]) + "," +
//                 to_string(t[2]);

//             // if (!s.count(key)) {
//             //   s.insert(key);
//             //   ans.push_back(t);
//             // }
//             if (s.insert(key).second) {
//               ans.push_back(t);
//             }
//           }
//         }
//       }
//     }
//     return ans;
//   }
// };

// Bug
// class Solution {
//  public:
//   vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<vector<int>> ans;
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     int i = 0;
//     // This only skips some duplicates at the "beginning", not "deduplicating
//     every i".
//     // Correct way: do it inside the for (i...) loop
//     // skip duplicate
//     while (i + 1 < n && nums[i] == nums[i + 1]) {
//       i++;
//     }
//     // fix nums[i] and use two pointer to find nums[j], nums[k]
//     for (; i < n; i++) {
//       int j = i + 1;
//       int k = nums.size() - 1;

//       while (j < k) {
//         // You skip duplicates at the beginning of while(j<k) (wrong timing)

//         // This makes you jump around before checking sum, may skip valid
//         solutions.
//         // skip identical nums[j]
//         while (j + 1 < n && nums[j] == nums[j + 1]) {
//           j++;
//         }
//         // skip identical nums[k]
//         while (k - 1 >= 0 && nums[k] == nums[k - 1]) {
//           k--;
//         }
//         // too small, move j larger
//         if (nums[j] + nums[k] < -nums[i]) {
//           j++;
//           // too large, move k smaller
//         } else if (nums[j] + nums[k] > -nums[i]) {
//           k--;
//         } else {
//           ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
//           // what to do for match?
//           break;
//         }
//       }
//     }
//     return ans;
//   }
// };

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        long long sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          j++;
        } else if (sum > 0) {
          k--;
        } else {
          // match
          ans.push_back({nums[i], nums[j], nums[k]});
          j++;
          k--;
          while (j < k && nums[j] == nums[j - 1]) {
            j++;
          }
          while (j < k && nums[k] == nums[k + 1]) {
            k--;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> tests = {{-1, 0, 1, 2, -1, -4}, {0, 1, 1}, {0, 0, 0}};

  for (auto& nums : tests) {
    auto answer = sol.threeSum(nums);
    cout << "[";
    for (int i = 0; i < (int)answer.size(); i++) {
      cout << "[";
      for (int j = 0; j < (int)answer[i].size(); j++) {
        cout << answer[i][j];
        if (j + 1 < (int)answer[i].size()) cout << ", ";
      }
      cout << "]";
      if (i + 1 < (int)answer.size()) cout << ", ";
    }
    cout << "]\n";
  }
}