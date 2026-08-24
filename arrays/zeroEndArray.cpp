#include <iostream>

using namespace std;

void shiftZerosToEnd(int arr[], int n);

int main()
{
    int array[10] = {1, 0, 1, 2, 3, 0, 0, 8, 0, 9};
    shiftZerosToEnd(array, 10);
}


void shiftZerosToEnd(int arr[], int n)
{
    int numZeros =  0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            numZeros++;
        } 
        else if(arr[i] != 0 && numZeros > 0)
        {
            arr[i - numZeros] = arr[i];
            arr[i]  = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}