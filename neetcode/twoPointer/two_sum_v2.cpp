#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSumBrute(std::vector<int>& numbers, int target) {
      int sum;
      std::vector<int> result;
      for (int i = 0;  i < numbers.size(); i++) {
          for (int j = i + 1; j < numbers.size(); j++) {
              sum = numbers[i] + numbers[j];
              if (target == sum) {
                std::cout << "ptr1: " << i << " ptr2: " << j << std::endl;
                result.push_back(i + 1);
                result.push_back(j+ 1);
                return result;
              } else if (sum > target) {
                break;
              }
          }
      }

      return result;
    }

    std::vector<int> twoSumOptimal(std::vector<int>& numbers, int target) {
      int sum;
      int left = 0;
      int right = numbers.size() - 1;
      std::vector<int> result;

      while (left < right) {
        sum = numbers[left] + numbers[right];
        if (sum == target) {
          std::cout << "ptr1: " << left << " ptr2: " << right << std::endl;
          result.push_back(left + 1);
          result.push_back(right + 1);
          return result;
        } else if (sum > target) {
          right--;
        } else {
          left++;
        }
      }

      return result;
    }
    
};


int main() {
  Solution solution;
  std::vector<int> nums = {-10,-5,0,3,7};
  int target = -2;
  std::vector<int> res;
  // res = solution.twoSumBrute(nums, target);
  res = solution.twoSumOptimal(nums, target);

  return 0;
}