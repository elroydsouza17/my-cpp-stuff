#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int max_count = 0;
        int count = 0;
        std::string max_str = "";
        std::string temp_str = "";
        for (int i = 0; i < s.size(); i++) {
            // check if char present in string
            bool is_present = false;
            for (int j = 0; j < temp_str.size(); j++) {
                if (s[i] == temp_str[j]) {
                    is_present = true;
                    break;
                }
            }

            // check if present update values as per substring
            if (is_present) {
                if (count > max_count) {
                    max_count = count;
                    max_str = temp_str;
                }
                count = 0;
                temp_str = "";
            }
            // if not present add to substring , and move to next char
            temp_str += s[i];
            count++;

            if (i == s.size() - 1 && count > max_count) {
              max_count = count;
              max_str = temp_str;
            }

            }
            std::cout << max_str << std::endl;
            std::cout << max_count << std::endl;
            return max_count;
        }

    int lengthOfLongestSubstringCorrect(std::string s) {
      int left = 0;
      int count = 0;
      int count_max = 0;
      std::string sub_str = "";
      std::unordered_set<char> set;

      for (int i = 0; i < s.size(); i++) {
        while ((set.insert(s[i])).second == false) {
          set.erase(s[left]);
          left += 1;
        }

        auto val = set.insert(s[i]);
        count = i - left + 1;
        if (count > count_max) {
          sub_str = s.substr(left, count);
          count_max = count;
        }
      }
      std::cout << count_max << std::endl;
      std::cout << sub_str << std::endl;
      return count_max;
    }
};

int main() {
  Solution solution;
  std::string str = "1R1T7";
  // solution.lengthOfLongestSubstring(str);
  solution.lengthOfLongestSubstringCorrect(str);


}