#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& nums, int low, int high);
void merge(std::vector<int>& nums, int low, int mid, int high);

int main() {
	std::vector<int> arr = {5, 1, 3, 9, 4, 2};
	merge_sort(arr, 0, arr.size() - 1);
  return 0;
}

void merge_sort(std::vector<int>& nums, int low, int high) {
	if(low >= high) {
		return;
	}
	int mid = low + ((high - low) / 2);
	merge_sort(nums, low, mid);
	merge_sort(nums, mid + 1, high);
	std::cout << low << "-" << high << std::endl;
	merge(nums, low, mid, high);
}

void merge(std::vector<int>& nums, int low, int mid, int high) {
	int pointer1 = low;
	int pointer2 = mid + 1;
	int temp_arr[high - low + 1];
	int temp_ptr = 0;

	while (pointer1 <= mid && pointer2 <= high) {
		if (nums[pointer1] <= nums[pointer2]) {
			temp_arr[temp_ptr] = nums[pointer1];
			pointer1++;
			temp_ptr++;
		} else {
			temp_arr[temp_ptr] = nums[pointer2];
			pointer2++;
			temp_ptr++;
		}
	}

	while (pointer1 <= mid) {
		temp_arr[temp_ptr] = nums[pointer1];
		pointer1++;
		temp_ptr++;
	}

	while (pointer2 <= high) {
		temp_arr[temp_ptr] = nums[pointer2];
		pointer2++;
		temp_ptr++;
	}

	for (int i = low; i <= high; i++) {
		nums[i] = temp_arr[i - low];
	}

	for (int i = low; i <= high; i++) {
		std::cout << nums[i] << " "; 
	}

	std::cout << std::endl;
}