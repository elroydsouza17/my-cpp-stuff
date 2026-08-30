#include <iostream>
#include <vector>
#include <unordered_set>

void isDuplicate(std::vector<int>& nums);

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    isDuplicate(nums);
}


void isDuplicate(std::vector<int>& nums)
{
    std::unordered_set<int> uniqueNums;

    for (int i = 0; i < nums.size(); i++)
    {
        if(uniqueNums.insert(nums[i]).second == false) {
            std::cout << "array has duplicate values" << std::endl;
            return;
        }
    }

    std::cout << "array has unique values" << std::endl;
}