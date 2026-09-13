#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <ctype.h> // to lowercase

struct ListNode {
  int value;
  ListNode* next;
};

bool HasDuplicate(const std::vector<int>& nums);
bool IsAnagram(std::string& s, std::string& t);
bool ValidParanthesis(std::string& str);
bool IsValidPalindrome(std::string& s);
void TwoSumBrute(std::vector<int>& nums, int target);
void TwoSum(std::vector<int>& nums, int target);
void PrintList(ListNode* head);
ListNode* ReverseList(ListNode* head);


int main() {
  std::vector<int> nums = {1, 2, 2, 3, 9 , 4, 1};
  bool result = HasDuplicate(nums);

  std::string s = "racecar";
  std::string t = "carrace";
  bool is_valid = IsAnagram(s, t) ;

  std::string str = "([{}])[]";
  bool is_valid_bracket = ValidParanthesis(str);

  std::string palindrome = "Was it a car or a cat I saw?";
  bool is_valid_palindrome = IsValidPalindrome(palindrome);

  std::vector<int> two_sum = {1, 2, 3, 4, 5};
  TwoSumBrute(two_sum, 18);
  TwoSum(two_sum, 18);

  ListNode list1;
  ListNode list2;
  ListNode list3;

  list1.value = 1;
  list2.value = 2;
  list3.value = 3;
  list1.next = &list2;
  list2.next = &list3;
  list3.next = NULL;

  PrintList(&list1);
  ListNode* head = ReverseList(&list1);
  PrintList(head);

  return 0;
}

//O(n^2) complexity
bool HasDuplicate(const std::vector<int>& nums) {
  std::unordered_set<int> hash_set;
  for (int i = 0; i < nums.size(); i++) {
    if (hash_set.find(nums[i]) != hash_set.end()) {
      std::cout << "Duplicate found is : " << nums[i] << std::endl;
      return true;
    } 
    hash_set.insert(nums[i]);
  }
  return false;
}

bool IsAnagram(std::string& s, std::string& t) {
  if (s.size() != t.size()) {
    return -1;
  }

  for (int i = 0; i < s.size(); i++) {
    bool found = false;
    for (int j = 0; j < t.size(); j++) {
      if(s[i] == t[j]) {
        s[i] = '\0';
        t[j] = '\0';
        found = true;
        break;
      }
    }
    if(!found) {
      std::cout << "Character not found , not valid anagram :" << s[i] << std::endl;
      return false;
    }
  }
  
    std::cout << "Valid anagram!!!" << std::endl;
    return true;


}

// Using vectors not stack ( kinda same )
bool ValidParanthesis(std::string& str) {
  if (str.size() % 2 != 0) {
    std::cout << "invalid parathesis exiting ...";
    return false;
  }

  std::vector<char> stack;
  int end = -1;
  std::unordered_map<char, char> hash_map;

  hash_map[')'] = '(';
  hash_map[']'] = '[';
  hash_map['}'] = '{';

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      stack.push_back(str[i]);
    } else if (stack.size() > 0 && hash_map[str[i]] == stack[stack.size() - 1]) {
      stack.pop_back();
    } else {
      std::cout << "invalid parathesis exiting ...";
      return false;
    }
  }

  if(stack.size() == 0) {
    return true;
  }
  std::cout << "invalid parathesis exiting ...";
  return false;
}

//VALID palindrome 
bool IsValidPalindrome(std::string& s) {
  int left = 0;
  int right = s.size() - 1;
  std::unordered_set<char> hash_set;

  //insert into hashset
  for (char i = 'a'; i <= 'z'; i++) {
    hash_set.insert(i);
  }

  for (char i = '0'; i <= '9'; i++) {
    hash_set.insert(i);
  }

  while(left <= right) {

    //
    while(left < s.size() && hash_set.find(std::tolower(s[left])) == hash_set.end()) {
      left++;
    }

    while(right >= 0 && hash_set.find(std::tolower(s[right])) == hash_set.end()) {
      right--;
    }

    if (left > right) {
      std::cout << "valid palindrome" << std::endl;
      return true;
    } else if (std::tolower(s[left]) == std::tolower(s[right])) {
      left++;
      right--;
    } else {
      std::cout << "Invalid palindrome" << std::endl;
      return false;
    }
  }

  std::cout << "valid palindrome" << std::endl;
  return true;
}

// Brute force O(n2)
void TwoSumBrute(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if(nums[i] + nums[j] == target) {
        std::cout << "Indices are: " << i << ", " << j << std::endl;
        return;
      }
    } 
  }

  std::cout << "no sum found!!!" << std::endl;
  return;
}

void TwoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hash_map;

  // insert hash_map if key already present this updates the value
  // if same number is present 2 times it will take the latest index. 
  // since only 1 unique solution exists the number won't be repeated more than twice
  for (int i = 0; i < nums.size(); i++) {
    hash_map[nums[i]] = i;
  }

  // loop through array
  for (int i = 0; i < nums.size(); i++) {
    if (hash_map.find(target - nums[i]) != hash_map.end() && hash_map[target - nums[i]] != i) {
      std::cout << "Indices are : " << i << ", " << hash_map[target - nums[i]] << std::endl;
      return;
    }
  }

  std::cout << "No solution exists!! "  << std::endl;
}

ListNode* ReverseList(ListNode* head) {
  ListNode* prev_ptr = NULL;
  ListNode* next_ptr = NULL;
  while (head != NULL) {
    next_ptr = head->next;
    head->next = prev_ptr;
    prev_ptr = head;
    head = next_ptr;
  }

  return prev_ptr;
}

void PrintList(ListNode* head) {
  ListNode* ptr = head;
  while(ptr != NULL) {
    std::cout << ptr->value << " " << std::endl;
    ptr = ptr->next;
  }
}
