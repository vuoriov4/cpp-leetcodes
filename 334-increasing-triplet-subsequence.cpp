class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int a = nums[0];
    int x = nums[0];
    optional<int> b = nullopt;
    int i = 1;
    while (i < nums.size()) {
      if (b.has_value() && b.value() < nums[i]) 
        return true;
      if ((!b.has_value() || b.value() > nums[i]) && a < nums[i]) 
        b = optional<int>{nums[i]};
      if (x < nums[i] && b.has_value() && b.value() > nums[i]) {
        a = x;
        b = optional<int>{nums[i]};
      }
      if (x > nums[i]) 
        x = nums[i]; 
      if (!b.has_value() && a > nums[i])
        a = nums[i];
      i += 1;
    }
    return false;
  }
};
