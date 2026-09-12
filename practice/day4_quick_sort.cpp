#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& nums, int low, int high);
int partition(std::vector<int>& nums, int low, int high);

int main() {
  std::vector<int> nums = {5, 1, 5};
  quick_sort(nums, 0, nums.size() - 1);
  for (int i = 0; i <nums.size(); i++) {
    std::cout << nums[i] << " ";
  }

  return 0;
}

void quick_sort(std::vector<int>& nums, int low, int high) {
  if (low >= high) {
    return;
  }

  int correct_pivot_index = partition(nums, low, high);

  quick_sort(nums, low, correct_pivot_index - 1);
  quick_sort(nums, correct_pivot_index + 1, high);
}

int partition(std::vector<int>& nums, int low, int high) {
  int pivot = nums[low];
  int left = low + 1;
  int right = high;
  int temp;
  while (left < right) {
  // scan from left till it finds a num greater than pivot
    while (left < high && nums[left] <= pivot) {
      left++;
    }

    //scan from right till it finds number less than pivot
    while(right > low && nums[right] > pivot) {
      right--;
    }

    // swap if legitimate swap
    if (left < right) {
      temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
    } 
  }

  //SWAP PIVOT after all elements are moved.
  nums[low] = nums[right];
  nums[right] = pivot;

  return right;
}