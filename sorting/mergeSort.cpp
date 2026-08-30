#include <iostream>
#include <vector>

void mergeSort(std::vector<int>& nums, int low, int high);
void merge(std::vector<int>& nums, int low, int high, int mid);
int main()
{
    std::vector<int> nums = {3, 1, 2, 4, 1, 5, 6, 2, 4};
    mergeSort(nums, 0, nums.size() - 1);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << " " << nums[i] ;
    }
    return 0;
}

void mergeSort(std::vector<int>& nums, int low, int high)
{
    if (low == high ) return;
    int mid = low + ((high - low) / 2);
    std::cout << low << "-" << high << "-" << mid << std::endl;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, high, mid);

}

void merge(std::vector<int>& nums, int low, int high, int mid)
{
    int pointer1 = low;
    int pointer2 = mid + 1;
    int temp_arr[high - low + 1];
    int temp_arrPtr = 0;

    // 
    while(pointer1 <= mid && pointer2 <= high) {
        if(nums[pointer1] <= nums[pointer2])
        {
            temp_arr[temp_arrPtr] = nums[pointer1];
            pointer1++;
            temp_arrPtr++;
        } 
        else 
        {
            temp_arr[temp_arrPtr] = nums[pointer2];
            pointer2++;
            temp_arrPtr++;
        }
    }

    while (pointer1 <= mid)
    {
        temp_arr[temp_arrPtr] = nums[pointer1];
        temp_arrPtr++;
        pointer1++;
    }

    while (pointer2 <= high)
    {
        temp_arr[temp_arrPtr] = nums[pointer2];
        temp_arrPtr++;
        pointer2++;
    }

    for(int i = 0; i < high - low + 1; i++)
    {
        nums[low + i] = temp_arr[i];
    }
    
}