#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    string s_clean{};
    for (char c : s) {
      if (isalnum(c)) {
        s_clean += tolower(c);
      }
    }
    int i = 0;
    int j = s_clean.size() - 1;
    while (i < j) {
      if (s_clean[i] != s_clean[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<string> strings{"A man, a plan, a canal: Panama", "race a car", " "};
  cout << boolalpha;
  for (string s : strings) {
    cout << sol.isPalindrome(s) << endl;
  }
  return 0;
}