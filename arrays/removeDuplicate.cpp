#include <iostream>

using namespace std;

template <size_t N>
void removeDuplicates(int (&arr)[N]);

template <size_t N>
void printArray(int (&arr)[N]);

int main()
{

    int array [] = { 1, 1, 5, 5, 5, 5, 7, 8, 10, 10, 10, 11, 12, 13, 13};

    printArray(array);
    removeDuplicates(array);
    cout << "Removing duplicates..." << endl;
    printArray(array);

    return 0;
}

template <size_t N>
void removeDuplicates(int (&arr)[N])
{
    int unique = arr[0];
    int position = 1;

    for(int i = 1; i < N; i++)
    {
        if(arr[i] == unique)
        {
            arr[i] = 0;
        }
        else
        {
            unique = arr[i];
            arr[i] = 0;
            arr[position] = unique;
            position++;
        }
    }
}

template <size_t N>
void printArray(int (&arr)[N])
{
    cout << "Array Contents: ";

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}