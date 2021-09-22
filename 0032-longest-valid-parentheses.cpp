class Solution {
public:
  int longestValidParentheses(string s) {
    int result = 0;
    int current = 0;
    int counter = 0;
    // scan from left
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') counter++;
      else counter--;
      if (counter < 0) { 
        counter = 0; 
        current = 0; 
      } else {
        current++;
        if (counter == 0) result = max(result, current);
      }
    }
    // scan from right
    current = 0;
    counter = 0;
    for (int i = s.size()-1; i >= 0; i--) {
      if (s[i] == ')') counter++;
      else counter--;
      if (counter < 0) { 
        counter = 0; 
        current = 0; 
      } else {
        current++;
        if (counter == 0) result = max(result, current);
      }
    }
    return result;
  }
};
