#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
  public:
    int largestSubstringWithoutDuplicates(std::string& s) {
      std::unordered_set<char> hash_set;
      std::vector<char> sub_str;
      int head = 0;
      int max_count = 0;
      for (int i = 0; i < s.size(); i++) {
        auto insert_result = hash_set.insert(s[i]);
        if (insert_result.second) {
          sub_str.push_back(s[i]);
          if ((sub_str.size() - head) > max_count) {
            max_count = sub_str.size() - head;
          }
        } else {
          // remove key from set
          //remove char from sub_str
          while (sub_str[head] != s[i]) {
            hash_set.erase(sub_str[head]);
            head++;
          }
          head++;
          sub_str.push_back(s[i]);
        }
      }
      std::cout << max_count << std::endl;
      return max_count;
    }
};

int main() {
  Solution solution;
  std::string s = "xxxxxx";
  solution.largestSubstringWithoutDuplicates(s);
}