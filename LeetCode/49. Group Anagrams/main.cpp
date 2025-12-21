#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
//  public:
//   vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     unordered_map<string, vector<string>>
//         map;  // sorted string, original strings
//     for (string& str : strs) {
//       string key = str;
//       sort(key.begin(), key.end());
//       map[key].push_back(str);
//     }
//     vector<vector<string>> answer;
//     for (auto [k, v] : map) {
//       vector<string> group;
//       for (string& s : v) {
//         group.push_back(s);
//       }
//       answer.push_back(group);
//     }
//     return answer;
//   }
// };

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (auto& s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      mp[key].push_back(s);
    }

    vector<vector<string>> ans;
    ans.reserve(mp.size());

    for (auto& [_, group] : mp) {
      ans.push_back(std::move(group));
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<string>> strs = {
      {"eat", "tea", "tan", "ate", "nat", "bat"}, {""}, {"a"}};

  vector<vector<string>> answer;
  for (auto str : strs) {
    answer = s.groupAnagrams(str);
    for (int i = 0; i < answer.size(); i++) {
      cout << "[";
      for (int j = 0; j < answer[i].size(); j++) {
        cout << answer[i][j] << ",";
      }
      cout << "]";
    }
    cout << endl;
  }

  return 0;
}