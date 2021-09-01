class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{') {
        stack.push(c);
      } else if (c == ')' || c == ']' || c == '}') {
        if (stack.empty()) return false;
        char x = stack.top();
        stack.pop();
        if (c == ')' && x != '(') return false;
        if (c == ']' && x != '[') return false;
        if (c == '}' && x != '{') return false;
      }
    }     
    return stack.empty();
  }
};
