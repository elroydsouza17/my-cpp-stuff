#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& nums);
void print_vector(std::vector<int>& nums);
void insertion_sort(std::vector<int>& nums);
int partition (std::vector<int>& nums, int low, int high);
void quick_sort (std::vector<int>& nums, int low, int high);
void merge_sort(std::vector<int>& nums, int low, int high);
void merge(std::vector<int>& nums, int low, int mid, int high);

int main() {
  std::vector<int> nums = {7, 1, 1, 3, 5, 3};
  print_vector(nums);
  merge_sort(nums, 0, nums.size() - 1);
  print_vector(nums);

}

void selection_sort(std::vector<int>& nums) {

  for (int i = 0; i < nums.size() - 1; i++) {
    int min_index = i;
    int temp;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] < nums[min_index]) {
        min_index = j;
      }
    }

    // swap 
    temp = nums[i];
    nums[i] = nums[min_index];
    nums[min_index] = temp;
  }
}

void insertion_sort(std::vector<int>& nums) {
  for (int i = 1; i < nums.size(); i++) {
    int temp;
    for (int j = i; j > 0; j--) {
      if (nums[j] < nums[j - 1]) {
        temp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = temp;
      } else {
        break;
      }
    }
  }
}

void quick_sort (std::vector<int>& nums, int low, int high) {
  if (low >= high) {
    return;
  }
  int correct_pivot_index = partition(nums, low, high);
  std::cout << "pivot index is: " << correct_pivot_index << std::endl;
  quick_sort(nums, low, correct_pivot_index - 1);
  quick_sort(nums, correct_pivot_index + 1, high);
}

int partition (std::vector<int>& nums, int low, int high) {
  int pivot = nums[low];
  int left = low + 1;
  int right = high;
  int temp;

  while (left < right) {

    while (left < high && nums[left] <= pivot) {
      left++;
    }

    while(right > low && nums[right] > pivot) {
      right--;
    }

    if(left < right) {
      temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
    }
  }

  // swap pivot
  nums[low] = nums[right];
  nums[right] = pivot;
  return right;
}

void merge_sort(std::vector<int>& nums, int low, int high) {
  if (low == high) {
    return;
  }

  int mid = low + ((high - low) / 2);
  std::cout << low << " - " <<  high << std::endl;
  merge_sort(nums, low, mid);
  merge_sort(nums, mid + 1, high);

  merge(nums, low, mid, high);
}

void merge(std::vector<int>& nums, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  std::vector<int> temp_arr;
  while (left <= mid && right <= high) {
    if (nums[left] <= nums[right]) {
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

  // copy to main
  for (int i = low; i <= high; i++) {
    nums[i] = temp_arr[i - low];
  } 
}

void print_vector(std::vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " "; 
  }
  std::cout << std::endl;
}

