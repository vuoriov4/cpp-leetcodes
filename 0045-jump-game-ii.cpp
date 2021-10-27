class Solution {
public:
  int jump(vector<int>& nums) {
    vector<bool> visited(nums.size(), false);
    return rec(nums, visited, nums.size() - 1, 0);
  }
  int rec(vector<int>& nums, vector<bool>& visited, int idx, int jumps) {
    if (idx == 0) return jumps;
    visited[idx] = true;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= abs(idx - i) && !visited[i]) {
        int j = rec(nums, visited, i, jumps + 1);
        if (j != -1) return j;
      }
    }
    return -1;
  }
};
