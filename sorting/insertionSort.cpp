#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& nums);

int main()
{
    std::vector<int> array = {3, 7, 12, 89, 2, 3, 3, 1, 5};
    insertionSort(array);

    for (int i = 0; i < array.size(); i++)
    {
        std::cout << " " << array[i];
    }
    return 0;
}

void insertionSort(std::vector<int>& nums)
{
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        for(int j = i ; j > 0; j--)
        {
            if(nums[j] < nums[j - 1])
            {
                temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
}