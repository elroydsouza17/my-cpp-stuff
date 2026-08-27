#include <iostream>

using namespace std;

void shiftZerosToEnd(int arr[], int n);
void printArray(int arr[], int n);
void shiftZerosToEndSimpler(int arr[], int n);

int main()
{
    int array[10] = {1, 0, 1, 2, 3, 0, 0, 8, 0, 9};
    // shiftZerosToEnd(array, 10);
    shiftZerosToEndSimpler(array, 10);
    printArray(array, 10);
}

// Complicated but same time and space complexity 
void shiftZerosToEnd(int arr[], int n)
{
    int numZeros =  0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            numZeros++;
        } 
        else if(numZeros > 0)
        {
            arr[i - numZeros] = arr[i];
            arr[i]  = 0;
        }
    }
}

//Simpler conditions and readable
void shiftZerosToEndSimpler(int arr[], int n)
{   
    int write = -1;
    // set write position pointer to oldest zero.
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            write = i;
            break;
        }
    }

    for (int i = write + 1; i < n; i++)
    {
        if(arr[i] != 0)
        {
            arr[write] = arr[i];
            arr[i] = 0;
            write++;
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }

    cout << endl;
}