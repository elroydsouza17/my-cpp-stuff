#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>

class Solution {
  // O(n*KlogK)
  public: std::vector<std::vector<std::string>> GroupAnagrams(std::vector<std::string>& list_anagrams) {
    std::unordered_map<std::string, int> map;
    std::vector<std::vector<std::string>> output;
    int count = 0;
    for (int i = 0; i < list_anagrams.size(); i++) {
      std::string sorted_str = list_anagrams[i];
      std::sort(sorted_str.begin(), sorted_str.end());
      if (auto result = map.insert({sorted_str, count}); result.second == true) {
        output.push_back({list_anagrams[i]});
        count++;
      } else {
        output[map[sorted_str]].push_back(list_anagrams[i]);
      }
    }
    return output;
  }

  std::vector<std::vector<std::string>> GroupAnagramsOptimal(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> output;
    struct ArrayHash {
      int operator()(const std::array<int, 26>& arr) const {
        int hash = 0;

        for (int count:arr) {
          hash = hash *  31 + count;
        }
        return hash;
      }
    };

    std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrayHash> map;

    for (int i = 0; i < strs.size(); i++) {
      std::array<int, 26> count_arr = {};
      for (int j = 0; j < strs[i].size(); j++) {
        count_arr[strs[i][j] - 'a']++;
      }

      map[count_arr].push_back(strs[i]);

    }


    for (const std::pair<const std::array<int, 26>,const std::vector<std::string>> &it: map) {
      output.push_back(it.second);
    }
    
    return output;
  }
};

int main() {
  Solution solution;
  // std::vector<std::string> list = {"act","pots","tops","cat","stop","hat"};
  std::vector<std::string> list = {""};
  auto result = solution.GroupAnagrams(list);

  for (int i = 0; i < result.size(); i++) {
  std::cout << "[";
    for (int j = 0; j < result[i].size(); j++) {
      std::cout << " " << result[i][j];
    }
  std::cout << "]";
  }
  std::cout << std::endl;

  std::cout << "=======optimal method below===========" << std::endl;

  for (int i = 0; i < result.size(); i++) {
  std::cout << "[";
    for (int j = 0; j < result[i].size(); j++) {
      std::cout << " " << result[i][j];
    }
  std::cout << "]";
  }
  std::cout << std::endl;
}