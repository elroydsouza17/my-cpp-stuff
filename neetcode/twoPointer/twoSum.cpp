#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashMap;
        std::vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            hashMap.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++) {
            auto it =  hashMap.find(target - nums[i]); 
            if (it != hashMap.end() && hashMap[target - nums[i]] != i && i < hashMap[target - nums[i]]) {
                indices.push_back(i);
                indices.push_back(it->second);
                return indices;
            } else if (it != hashMap.end() && hashMap[target - nums[i]] != i && i > hashMap[target - nums[i]]) {
                indices.push_back(it->second);
                indices.push_back(i);
                return indices;
            }
        }

        return indices;
    }
};


int main() {
  std::vector<int> arr = {3, 2, 3};
  Solution solution;
  std::vector<int> test = solution.twoSum(arr, 6);
  for (int i = 0; i < test.size(); i++) {
    std::cout << test[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}