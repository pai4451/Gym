#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty()) {
      return "";
    }
    unordered_map<char, int> need;
    for (char c : t) {
      need[c]++;
    }
    int needKinds = need.size();  // number of distinct characters in t
    int have = 0;                 // number of requirements currently satisfied

    unordered_map<char, int> window;
    int left = 0;
    int bestLen = INT_MAX;
    int bestL = 0;

    for (int right = 0; right < s.size(); right++) {
      char c = s[right];
      window[c]++;

      // this character just reached the required count
      if (need.count(c) && window[c] == need[c]) {
        have++;
      }

      // while all requirements are met, try to shrink from the left
      while (have == needKinds) {
        int windowLen = right - left + 1;
        if (windowLen < bestLen) {
          bestLen = windowLen;
          bestL = left;
        }

        // prepare to remove the left character
        char d = s[left];
        window[d]--;
        if (need.count(d) && window[d] < need[d]) {
          have--;
        }
        left++;
      }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
  }
};

int main() {
  Solution sol;
  vector<pair<string, string>> tests{
      {"ADOBECODEBANC", "ABC"}, {"a", "a"}, {"a", "aa"}};

  for (auto [s, t] : tests) {
    cout << sol.minWindow(s, t) << endl;
  }

  return 0;
}