class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::vector<int> result;
    unordered_map<int, int> num_to_freq;
    priority_queue<pair<int, int>> freq_to_nums; 
    for (int x: nums) num_to_freq[x]++;
    for (auto p: num_to_freq) freq_to_nums.push(make_pair(p.second, p.first));
    for (int i = 0; i < k; i++) {
      result.push_back(freq_to_nums.top().second);
      freq_to_nums.pop();
    }
    return result;
  }
};
