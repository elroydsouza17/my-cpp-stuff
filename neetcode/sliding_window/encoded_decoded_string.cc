#include <iostream>
#include <vector>
#include <string>

class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        std::string encoded_str = "";
        for (int i = 0; i < strs.size(); i++) {
            encoded_str = encoded_str + std::to_string(strs[i].size()) + ':' + strs[i];
        }

        return encoded_str;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> decoded_str;
        int ptr1 = 0;
        std::string sub_str_size = "";
        std::string str = "";

        for (int i = 0; i < s.size(); i++) {
          if (s[i] != ':') {
            sub_str_size += s[i];
            continue;
          } else {
            int count = std::stoi(sub_str_size);
            while (count != 0) {
              i++;
              str += s[i];
              count--;
          }

          decoded_str.push_back(str);
          str = "";
          sub_str_size = "";
          }
        }
    
        return decoded_str;
    }
};


int main () {
  std::vector<std::string> input = {"Hello", "Elroy"};
  Solution solution;
  std::string encoded_str = solution.encode(input);
  std::cout << encoded_str << std::endl;
  auto decoded_str = solution.decode(encoded_str);
  for (int i = 0; i < decoded_str.size(); i++) {
    std::cout << decoded_str[i] << " " ;
  }
  std::cout << std::endl;
  return 0;
}