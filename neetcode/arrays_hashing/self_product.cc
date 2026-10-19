#include <iostream>
#include <vector>

class Solution {
public:
    void productExceptSelf(std::vector<int>& nums) {
      int prefix[nums.size()];
      int postfix[nums.size()];
      std::vector<int> output;
      int res = 1;
      for (int i = 0; i < nums.size(); i++) {
        res *= nums[i];
        prefix[i] = res;
      }

      res = 1;
      int head = 0;
      for (int i = nums.size() - 1; i >= 0; i--) {
        res *= nums[i];
        postfix[i] = res;
      }

      for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
          output.push_back(1 * postfix[i + 1]);
          continue;
        } else if(i == nums.size() - 1) {
          output.push_back(prefix[i - 1] * 1);
          continue;
        }
        output.push_back(prefix[i - 1] * postfix[i + 1]);
      }

      std::cout << "OUTPUT ARRAY" << std::endl;
      for (int i = 0; i < nums.size(); i++) {
        std::cout << output[i] << " ";
      }
      std::cout << std::endl;
      std::cout << "prefix ARRAY" << std::endl;
      for (int i = 0; i < nums.size(); i++) {
        std::cout << prefix[i] << " ";
      }
      std::cout << std::endl;
      std::cout << "Postfix ARRAY" << std::endl;
      for (int i = 0; i < nums.size(); i++) {
        std::cout << postfix[i] << " ";
      }
      std::cout << std::endl;

      // return output;
    }

    // with Memory / space complexity is O(n)
      void productExceptSelfOptimal(std::vector<int>& nums) {
      int output[nums.size()];
      int prefix = 1;
      for (int i = 0; i < nums.size(); i++) {
        output[i] = prefix;
        prefix *= nums[i];
      }

      int postfix = 1;
      for (int i = nums.size() - 1; i >= 0; i--) {
        output[i] = postfix * output[i];
        postfix *= nums[i];
      }

      std::cout << "OUTPUT ARRAY" << std::endl;
      for (int i = 0; i < nums.size(); i++) {
        std::cout << output[i] << " ";
      }


      }
    };

int main() {
  std::vector<int> num = {1, 2, 4, 6};
  Solution solution;
  // solution.productExceptSelf(num);
  solution.productExceptSelfOptimal(num);
}
