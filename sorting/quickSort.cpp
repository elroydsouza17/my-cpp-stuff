#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int high, int low);

int main()
{
    std::vector<int> arr = {5, 1, 6, 9, 3, 8};

    for( int i =  0; i < arr.size(); i++)
    {
        std::cout << " " << arr[i];
    }
    std::cout << "" << std::endl;

    quickSort(arr, 0, arr.size() - 1);

    for( int i =  0; i < arr.size(); i++)
    {
        std::cout << " " << arr[i];
    }

    return 0;
}

// call recursively
void quickSort(std::vector<int>& arr, int low, int high)
{
    if(low < high)
    {
    int partitionIdx = partition(arr, low, high);

    quickSort(arr, low, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, high);
    }
}

// 2 pointer approach and swap elements
int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    
    int pointer1 = low;
    int pointer2 = high;
    int temp = -1;
    while (pointer1 < pointer2)
    {
        while(arr[pointer1] <= pivot && pointer1 <= high - 1)
        {
            pointer1++;
        }

        while(arr[pointer2] > pivot && pointer2 >= low + 1)
        {
            pointer2--;
        }

        if(pointer1 < pointer2)
        {
            temp = arr[pointer1];
            arr[pointer1] = arr[pointer2];
            arr[pointer2] = temp;
        }
    }

    arr[low] = arr[pointer2];
    arr[pointer2] = pivot; 

    return pointer2;
}
