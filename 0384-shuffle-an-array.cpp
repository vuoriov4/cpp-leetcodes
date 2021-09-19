class Solution {
public:
  vector<int>* orig;
  vector<int> data;
  
  Solution(vector<int>& nums) {
    orig = &nums;
    data = nums;
  }
  
  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    data = *orig;
    return data;
  }
  
  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for (int i = data.size() - 1; i > 0; i--) {
      int r = random(0, i);
      swap(data, r, i);
    }
    return data;
  }
  
  void swap(vector<int>& data, int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
  
  int random(int min, int max) {
    return min + rand() % (( max + 1 ) - min);
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
