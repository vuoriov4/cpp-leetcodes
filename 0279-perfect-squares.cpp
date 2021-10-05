class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    return rec(n, dp);
  }
  int rec(int n, vector<int>& dp) {
    if (n < 0) {
      return INT_MAX - 1;  
    } else if (dp[n] > 0) 
      return dp[n];
    else {
      int minimum = n;
      for (int i = floor(sqrt(n)); i > 0; i--) {
        int ps = i * i;
        minimum = min(minimum, rec(n - ps, dp) + 1); 
      }
      dp[n] = minimum;
      return minimum;
    }
  }
};
