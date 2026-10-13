#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

void quickSort(std::vector<int>& nums, int low, int high);
int partition(std::vector<int>& nums, int low, int high);
void printVector(std::vector<int>& num);

class Solution {
  public:
    void threeSumBrute(std::vector<int>& nums, int target) {
      for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
          for (int k = j + 1; k < nums.size(); k++) {
            if (nums[i] + nums[j] + nums[k] == target) {
              std::cout << " " << i << " " << j << " " << k <<  std::endl;
            }
          }
        }
      }

    }

    void threeSumHashMap(std::vector<int>& nums_sorted, int target) {
      for (int i = 0; i < nums_sorted.size() - 2; i++) {
        if (i > 0 && nums_sorted[i - 1] == nums_sorted[i]) {
          continue;
        }
        // find two sum such that target - i is the target.
        std::unordered_map<int, int> hash_map;
        for (int j = i + 1; j < nums_sorted.size(); j++) {
          hash_map[nums_sorted[j]] = j; // do not use insert here.
        }

        for (int j = i + 1; j < nums_sorted.size(); j++) {
          if (j > i + 1 && nums_sorted[j] == nums_sorted[j - 1]) {
            continue;
          }
          if (auto it = hash_map.find(target - nums_sorted[i] - nums_sorted[j]); it != hash_map.end() && it->second > j /*used to prevent duplicate triplets*/) {
            std::cout << nums_sorted[i] << " " << nums_sorted[j] << " " << it->first << std::endl;
          }
        }
      }
    }
};

int main() {
  Solution solution;
  std::vector<int> s = {-1,0,1,2,-1,-4};
  quickSort(s, 0, s.size() - 1);
  printVector(s);
  // solution.threeSumBrute(s, 0);
  solution.threeSumHashMap(s, 0);
}

void quickSort(std::vector<int>& nums, int low, int high) {
  if (low >= high) {
    return;
  }

  int pivot_idx = partition(nums, low, high);
  quickSort(nums, low, pivot_idx - 1);
  quickSort(nums, pivot_idx + 1, high);
}

int partition(std::vector<int>& nums, int low, int high) {
  int pivot = nums[low];
  int left = low;
  int right = high;
  int temp;

  while (left < right) {
    //stop at element greater than pivot or at the end
    while (left < high && nums[left] <= pivot) {
      left++;
    }

    //stop at element lesser equal to  pivot or at the end
    while (right > low && nums[right] > pivot) {
      right--;
    }

    if (left < right) {
      temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
    }
  }

  nums[low] = nums[right];
  nums[right] = pivot;
  return right;
}

void printVector(std::vector<int>& num) {
  for (int i = 0; i < num.size(); i++) {
    std::cout << num[i] << " " ;
  }
  std::cout << std::endl;
}