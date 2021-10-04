class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    vector<vector<int>> dp(matrix.size(),  vector<int>(matrix[0].size(), 0));
    int result = 0;
    for (int col = 0; col < matrix.size(); col++) {
      for (int row = 0; row < matrix[0].size(); row++) {
        char c = matrix[col][row];
        if (c == '0') continue;
        char up = col > 0 ? matrix[col-1][row] - '0'  : 0;
        char left = row > 0 ? matrix[col][row-1] - '0'   : 0;
        char diag = (row > 0 && col > 0) ? matrix[col-1][row-1]  - '0' : 0;
        if (up > 0 && left > 0 && diag > 0) 
          matrix[col][row] = min(min(up, left), diag) + 1;
        result = max(result, (int) matrix[col][row]);
      }
    }
    return result * result;
  }
};
