#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last;  // char, last occurence
    int left = 0;
    int best = 0;

    for (int right = 0; right < s.size(); right++) {
      unsigned char c = s[right];
      if (last.count(c) && last[c] >= left) {
        left = last[c] + 1;
      }
      last[c] = right;

      best = max(best, right - left + 1);
    }
    return best;
  }
};

int main() {
  vector<string> tests{"abcabcbb", "bbbbb", "pwwkew"};
  Solution sol;
  for (string s : tests) {
    cout << sol.lengthOfLongestSubstring(s) << endl;
  }
  return 0;
}