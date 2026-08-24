#include <iostream>

using namespace std;

void rotateLeftBrute(int arr[], int n, int rotations);
void printArray(int arr[], int n);

int main()
{
    int array[8] = {1, 2, 3, 4, 5, 0 , 9, 7};
    rotateLeftBrute(array, 8, 2);
    printArray(array, 8);

    return 0;
}

void rotateLeftBrute(int arr[], int n, int rotations)
{
    rotations = rotations % n;

    int temp[rotations];

    for (int i = 0; i < rotations; i++)
    {
        temp[i] = arr[i];
    }

    for (int j = rotations; j < n; j++)
    {
        arr[j - rotations] = arr[j];
    }

    for(int k = 0; k < rotations; k++)
    {
        arr[n - rotations + k] = temp[k];
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

