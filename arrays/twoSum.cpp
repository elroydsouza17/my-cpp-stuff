#include <iostream>

using namespace std;


template <size_t N>
void twoSum(int (&array)[N], int target, int (&result)[2]);

int main()
{

    int idxArray[2];
    int arr[] = {1, 4, 3, 6, 7, 13};
    int target;

    cout << "Enter target : ";
    cin >> target;

    twoSum(arr, target, idxArray);

    for(int i = 0; i < 2; i++)
    {
        cout << idxArray[i] << endl;
    }

    return 0;
}

template <size_t N>
void twoSum(int (&array)[N], int target, int (&result)[2])
{

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if((array[i] + array[j] == target) && (i != j))
            {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }

    cout << "No elements found for Two sum !!";
}