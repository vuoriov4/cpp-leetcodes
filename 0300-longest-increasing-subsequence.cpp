class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;
    int result = 0;
    if (nums.size() == 0) return 0;
    lis.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      for (int j = lis.size() - 1; j >= 0; j--) {
        if (j == lis.size() - 1 && nums[i] > lis[j]) lis.push_back(nums[i]);
        else if (j > 0 && nums[i] > lis[j-1] && nums[i] < lis[j]) { lis[j] = nums[i]; break; }
        else if (nums[i] < lis[0]) lis[0] = nums[i];
      }  
    }
    return lis.size();
  }
};
