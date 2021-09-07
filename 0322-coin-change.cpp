class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1);
    return numCoins(dp, coins, amount);
  }
  int numCoins(vector<int>& dp, vector<int>& coins, int amount) {
    if (amount < 0) return -1;
    else if (amount == 0) return 0;
    else if (dp[amount] != 0) return dp[amount];
    else {
      int minCoins = INT_MAX;
      for (int i = 0; i < coins.size(); i++) {
        int nc = numCoins(dp, coins, amount - coins[i]);
        if (nc >= 0) minCoins = min(minCoins, 1 + nc);
      }
      if (minCoins == INT_MAX) minCoins = -1;
      dp[amount] = minCoins;
      return minCoins;
    }
  }
};
