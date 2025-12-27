#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> cnt;
    int left = 0;
    int maxCount = 0;
    int best = 0;

    for (int right = 0; right < (int)s.size(); right++) {
      cnt[s[right]]++;
      maxCount = max(maxCount, cnt[s[right]]);

      while ((right - left + 1) - maxCount > k) {
        cnt[s[left]]--;
        left++;
      }

      best = max(best, right - left + 1);
    }

    return best;
  }
};

int main() {
  Solution sol;
  vector<string> strings{"ABAB", "AABABBA", "ABBB", "BAAAB"};
  vector<int> ks = {2, 1, 2, 2};
  for (int i = 0; i < strings.size(); i++) {
    cout << sol.characterReplacement(strings[i], ks[i]) << endl;
  }
  return 0;
}