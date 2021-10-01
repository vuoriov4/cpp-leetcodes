class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int h = grid.size();
    int w = grid[0].size();
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = grid[0][0];
    int i0 = 0;
    int j0 = 0;
    if (j0 < h-1) j0 += 1;
    else i0 += 1;
    while (i0 < w) {
      int i = i0;
      int j = j0;
      while (j >= 0 && i < w) {
        int left_cost = (i-1 >= 0) ? dp[j][i-1] : INT_MAX;
        int up_cost = (j-1 >= 0) ? dp[j-1][i] : INT_MAX;
        dp[j][i] = grid[j][i] + min(left_cost, up_cost);
        i += 1;
        j -= 1;
      }
      if (j0 < h-1) j0 += 1;
      else i0 += 1;
    }
    return dp[h-1][w-1];
  }
};
