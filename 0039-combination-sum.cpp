class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> s;
    vector<vector<int>> solution;
    dfs(candidates, s, solution, target, 0);
    return solution;
  }
  void dfs(vector<int>& candidates, vector<int>& s, vector<vector<int>>& solution, int target, int c) {
    if (target < 0) return;
    else if (target == 0) {
    vector<int> path(s);
    solution.push_back(path);
    } else {
    for (int x : candidates) {
      if (x < c) continue;
      s.push_back(x);
      dfs(candidates, s, solution, target - x, x);
      s.pop_back();
    }
    }
  }
};
