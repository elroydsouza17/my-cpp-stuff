#include <iostream>
#include <vector>

int partition(std::vector<int>& nums, int low, int high);
void quick_sort(std::vector<int>& nums, int low, int high);

int main() {
	std::vector<int> nums = {8, 3, 6, 1, 7, 2, 7, 1};
	quick_sort(nums, 0, nums.size() - 1);
	return 0;
}

void quick_sort(std::vector<int>& nums, int low, int high) {
	if (low >= high) {
		return;
	}
	int pivot_position = partition(nums, low, high);
	quick_sort(nums, low, pivot_position - 1);
	quick_sort(nums, pivot_position + 1, high);
}

int partition(std::vector<int>& nums, int low, int high) {
	// pick a pivot
	int pivot = nums[low]; 
	int pointer1 = low;
	int pointer2 = high;
	int temp;

	// swap smaller elements to the left and larger to the right. 
	while (pointer1 < pointer2) {
		
		while(pointer1 <= high - 1 && nums[pointer1] <= pivot)	{
			pointer1++;
		}

		while(pointer2 >= low + 1 && nums[pointer2] > pivot) {
			pointer2--;
		}

		// nums[pointer1] > pivot && nums[pointer2] < pivot && pointer1 < pointer2,
		// the first 2 conditions are guaranteed by the while loops above
		// hence only the last condition needs to be checked.
		if (pointer1 < pointer2)  {
			temp = nums[pointer1];
			nums[pointer1] = nums[pointer2];
			nums[pointer2] = temp;
		}
		
	}

	nums[low] = nums[pointer2];
	nums[pointer2] = pivot;

	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " " ;
	}
	std::cout << std::endl;

	return pointer2;


}