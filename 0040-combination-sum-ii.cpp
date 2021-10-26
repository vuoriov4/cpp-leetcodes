class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> sln;
    vector<int> Stack;
    map<int, int> cmap;
    for (int i = 0; i < candidates.size(); i++) {
      cmap[candidates[i]] = cmap[candidates[i]] + 1;
    }
    dfs(sln, Stack, cmap, target);
    return sln;
  }
  void dfs(vector<vector<int>>& sln, vector<int>& Stack, map<int, int>& cmap, int target) {
    if (target < 0) return;
    else if (target == 0) sln.push_back(vector<int>(Stack));
    else {
      int current = Stack.size() > 0 ? Stack.back() : INT_MIN;
      for (auto it = cmap.begin(); it != cmap.end(); ++it) {
        int next = it->first;
        if (cmap[next] == 0 || next < current) continue;
        cmap[next] -= 1;
        Stack.push_back(next);
        dfs(sln, Stack, cmap, target - next);
        cmap[next] += 1;
        Stack.pop_back();
      }
    }
  }
};
