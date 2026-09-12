#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& nums, int low, int high);
void merge(std::vector<int>& nums, int low, int mid, int high);

int main() {
  std::vector<int> nums = {56, 1, 3, 8, 23};
  merge_sort(nums, 0, nums.size() - 1);
  for (int i = 0; i <nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
}

void merge_sort(std::vector<int>& nums, int low, int high) {
  // base function to stop
  if (low == high) {
    return;
  }

  // find mid point first to split array
  int mid = low + (high - low) / 2;
  std::cout << low << "-" << high << std::endl;
  merge_sort(nums, low, mid);
  merge_sort(nums, mid + 1, high);

  merge(nums, low, mid, high);

}

void merge(std::vector<int>& nums, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  std::vector<int> temp_arr;

  while (left <= mid && right <= high) {

    if(nums[left] <= nums[right]) {
      temp_arr.push_back(nums[left]);
      left++;
    } else {
      temp_arr.push_back(nums[right]);
      right++;
    }
  }

  while (left <= mid) {
    temp_arr.push_back(nums[left]);
    left++;
  }

  while (right <= high) {
    temp_arr.push_back(nums[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    nums[i] = temp_arr[i - low];
  }
}