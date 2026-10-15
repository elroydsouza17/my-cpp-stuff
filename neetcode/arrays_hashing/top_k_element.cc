#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;
        std::vector<std::vector<int>> bucket(nums.size() + 1);
        std::vector<int> result;
        // count elements O(n)
        for (int i = 0; i < nums.size(); i++) {
            auto result = freq_map.insert({nums[i], 1});
            if (!result.second) {
                freq_map[nums[i]]++;
            }
        }

        // O(n)
        for (const std::pair<const int, const int>& it: freq_map) {
            bucket[it.second].push_back(it.first);
        }

        // O(n)
        for (int i = bucket.size() - 1; i >= 0; i--) {
            std::vector<int> ele = bucket[i];
            while (!ele.empty()) {
                result.push_back(ele[ele.size() - 1]);
                ele.pop_back();
                if (result.size() == k) {
                    return result;
                }
            }   
        }

        return result;
    }
};

int main() {
  std::vector<int> nums = {7, 7};
  Solution solution;
  auto result = solution.topKFrequent(nums, 1);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " " ;
  }
}
