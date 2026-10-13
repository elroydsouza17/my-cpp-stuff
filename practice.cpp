#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> hash_map_s;
        std::unordered_map<char, int> hash_map_t;
        
        for (int i = 0; i < s.size(); i++) {
            auto result = hash_map_s.insert({s[i], 1});
            if (!result.second) {
                hash_map_s[s[i]]++;
            } 
        }

        for (int i = 0; i < t.size(); i++) {
            auto result = hash_map_t.insert({t[i], 1});
            if (!result.second) {
                hash_map_t[t[i]]++;
            } 
        }

        for (const std::pair<const char,const int>& it: hash_map_s) {
          std::cout << "key: " << it.first << " value: " << it.second << std::endl;
        }

        for (const std::pair<const char,const int>& it: hash_map_t) {
          std::cout << "key: " << it.first << " value: " << it.second << std::endl;
        }

        for (const std::pair<const char,const int>& it: hash_map_s) {
            if (!(hash_map_t[it.first] == it.second)) {
                return false;
            }
        }

        return true;
    }
};

int main()  {
  Solution solution;
  std::string s = "jam";
  std::string t = "jar";
  bool result = solution.isAnagram(s, t);
  std::cout << result << std::endl;

}
