#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// class Solution {
//  public:
//   bool isValid(string s) {
//     stack<char> stk;
//     for (char c : s) {
//       if (c == '(' || c == '{' || c == '[') {
//         stk.push(c);
//       }
//       if (c == ')' || c == '}' || c == ']') {
//         if (s.empty()){
//             return false;
//         }
//         char x = stk.top();
//         stk.pop();
//         if (c == ')' && x != '(') {
//           return false;
//         }
//         if (c == '}' && x != '{') {
//           return false;
//         }
//         if (c == ']' && x != '[') {
//           return false;
//         }
//       }
//     }
//     if (!stk.empty()) {
//       return false;
//     }
//     return true;
//   }
// };

class Solution {
 public:
  bool isValid(string s) {
    if (s.size() % 2 == 1) return false;

    stack<char> stk;
    for (char c : s) {
      if (c == '(' || c == '{' || c == '[') {
        stk.push(c);
      } else {  // must be ')', '}', or ']'
        if (stk.empty()) return false;
        char x = stk.top();
        stk.pop();

        if ((c == ')' && x != '(') || (c == '}' && x != '{') ||
            (c == ']' && x != '[')) {
          return false;
        }
      }
    }
    return stk.empty();
  }
};

int main() {
  vector<string> tests{"()", "()[]{}", "(]"};

  Solution sol;
  cout << boolalpha;
  for (string s : tests) {
    cout << sol.isValid(s) << endl;
  }
  return 0;
}