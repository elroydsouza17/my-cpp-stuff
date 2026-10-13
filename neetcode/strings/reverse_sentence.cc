#include <iostream>
#include <vector>
void reverse(std::string& str);

int main() {
  std::string sentence = "a good   example";
  reverse(sentence);
  return 0;
}

void reverse(std::string& str) {

  std::vector<char> reverse_str;
  int start = 0;
  int end = str.size() - 1;

  // remove leading spaces 
  while(str[start] == ' ') {
    start++;
  }
  
  // remove trailing spaces
  while(str[end] == ' ') {
    end--;
  }

  int ptr = 0;
  for (int i = start; i <= end; i++) {
    if (str[i] == ' ') {
      reverse_str.insert(reverse_str.begin(), ' ');
      while (str[i] == ' ') {
        i++;
      }
      reverse_str.insert(reverse_str.begin(), str[i]);
      ptr = 1;
    } else {
      reverse_str.insert(reverse_str.begin() + ptr, str[i]);
      ptr++;
    }
  }

  for (int i = 0; i < reverse_str.size(); i++) {
    std::cout << reverse_str[i];
  }

  std::cout << std::endl;
}