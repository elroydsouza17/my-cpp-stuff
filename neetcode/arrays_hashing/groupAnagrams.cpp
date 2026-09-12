#include <iostream>
#include <vector>
#include <unordered_map>

int main() {

}

std::vector<<std::vector<string>> validate_group_anagram(std::vector<string>& strs) {
  std::unordered_map<char, int> temp_hash;
  std::<vector<<std::vector<string>> final_str_array;

  // insert string into hashmap O(n + N)
  for (int i = 0; i < strs.size(); i++) {
    std::vector<std::unordered_map> hash_array;
    for (int j = 0; j < strs[i].size(); j++) {
      result = temp_hash.insert({j, 1});
      if (result.second == false) {
        temp_hash[j]++;
      }
    }
    bool is_present = true;
    // check if hashmap exists in hasharray O(k)
    for (int k = 0; k < hash_array.size(); k++) {
        for (auto [key, val]:temp_hash) {
          if (temp_hash[key] != hash_array[k][key]) {
            continue;
          } 
        }
    }
  }

}