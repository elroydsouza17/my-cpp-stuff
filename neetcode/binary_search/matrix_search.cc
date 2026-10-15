#include <iostream>
#include <vector>

// FIX ME !!!
// NOT WORKING FOR EDGE CASE Problem with while loop most probably
// using <= sends it into an infinite loop
class Solution {
  public:std::vector<int> searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int left = 0;
    int right = matrix.size() - 1;
    int mid;
    std::vector<int> output;
    while (left < right) {
       mid = (left + right) / 2;
      if (target == matrix[mid][matrix[mid].size() - 1]) {
        std::cout << mid << " " <<  matrix[mid].size() - 1 << std::endl;
        output.push_back(mid);
        output.push_back(matrix[mid].size() - 1);
        return output;
      } else if (target < matrix[mid][matrix[mid].size() - 1]) {
        right = mid;
        if (left == right) {
          int left_col = 0;
          int right_col = matrix[left].size() - 1;
          int mid_col;
          while(left_col <= right_col) {
            mid_col = (left_col + right_col) / 2;
            if (target == matrix[left][mid_col]) {
              std::cout << mid << " " << mid_col << std::endl;
              output.push_back(mid);
              output.push_back(mid_col);
              return output;
            } else if (target > matrix[left][mid_col]) {
              left_col = mid_col + 1;
            } else {
              right_col = mid_col - 1;
            }
          }
          return output;
        }
      } else {
        left = mid + 1;
        if (left == right) {
          int left_col = 0;
          int right_col = matrix[left].size() - 1;
          int mid_col;
          while(left_col <= right_col) {
            mid_col = (left_col + right_col) / 2;
            if (target == matrix[left][mid_col]) {
              std::cout << left << " " << mid_col << std::endl;
              output.push_back(left);
              output.push_back(mid_col);
              return output;
            } else if (target > matrix[left][mid_col]) {
              left_col = mid_col + 1;
            } else {
              right_col = mid_col - 1;
            }
          }
          return output; 
        }

      }
    }
    
    return output;
  }
};

int main() {
  std::vector<std::vector<int>> arr = {{1}};
  Solution solution;
  auto result = solution.searchMatrix(arr, 1);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";  
  }
  std::cout << std::endl;
}