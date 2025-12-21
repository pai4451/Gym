#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//  public:
//   vector<int> productExceptSelf(vector<int>& nums) {
//     int expectedProduct = 1;
//     for (auto& num : nums) {
//       expectedProduct *= num;
//     }
//     vector<int> answer(nums.size(), 1);
//     for (int i = 0; i < nums.size(); i++) {
//       if (nums[i] == 0) {
//         // do differently
//         for (int j = 0; j < nums.size(); j++) {
//           if (j != i) {
//             answer[i] *= nums[j];
//           }
//         }
//       } else {
//         answer[i] = expectedProduct / nums[i];
//       }
//     }
//     return answer;
//   }
// };

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);

    // prefix product
    int prefix = 1;
    for (int i = 0; i < n; i++) {
      answer[i] *= prefix;
      prefix *= nums[i];
    }
    // suffix product
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
      answer[i] *= suffix;
      suffix *= nums[i];
    }
    return answer;
  }
};

int main() {
  Solution s;
  vector<vector<int>> nums = {{1, 2, 3, 4}, {-1, 1, 0, -3, 3}};
  for (auto& num : nums) {
    auto answer = s.productExceptSelf(num);
    for (auto& x : answer) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}