#include <iostream>
#include <climits>
#include <vector>

void selectionSort(std::vector<int>& nums);

int main()
{
    std::vector<int> array = {3, 7, 12, 89, 2, 3, 3, 1, 5};
    selectionSort(array);
    return 0;
}

void selectionSort(std::vector<int>& nums)
{
    int temp;

    // find min and swap with 1st element incrementally
    for (int i = 0; i < nums.size(); i++) {
        int minIdx = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if(nums[j] < nums[minIdx]) {
                minIdx = j;
            }
        }

        temp = nums[i];
        nums[i] = nums[minIdx];
        nums[minIdx] = temp;

    }

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << " " << nums[i];
    }
     
}