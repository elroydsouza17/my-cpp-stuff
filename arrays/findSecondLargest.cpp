#include <iostream>
#include <climits>

using namespace std;

template <size_t N>
void sortArray(int (&arr)[N]);

template <size_t N>
void printArray(int (&arr)[N]);

template <size_t N>
int findSecondLargestBrute(int (&arr)[N]);

template <size_t N>
int findSecondLargestBetter(int (&arr)[N]);

template <size_t N>
int findSecondLargestOptimal(int (&arr)[N]);

template <size_t N>
int findSecondSmallestOptimal(int (&arr)[N]);

int main()
{
    int array [] = {3, 32, 3, 3, 99, 99, 12, 4};

    int num = findSecondLargestOptimal(array);
    cout << "Second largest no : " << num << endl;

    int Snum = findSecondSmallestOptimal(array);
    cout << "Second smallest no : " << Snum << endl;

    return 0;
}

template <size_t N>
void sortArray(int (&arr)[N])
{
    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < N - 1; i++)
        {
            int temp = 0;

            if(arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        printArray(arr, N);
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

template <size_t N>
int findSecondLargestBrute(int (&arr)[N])
{
    sortArray(arr);
    int largest = arr[N - 1];
    int secondLargest = 0;
    for(int i = N - 2; i >= 0; i--)
    {
        if(arr[i] != largest)
        {
            secondLargest = arr[i];
            break;
        }
    }

    return secondLargest;
}

template <size_t N>
int findSecondLargestBetter(int (&arr)[N])
{
    int largest = arr[0];
    int secondLargest = -1;

    for(int i = 1; i < N; i++)
    {
        if(largest < arr[i])
        {
            largest = arr[i];
        }
    }

    for(int j = 0; j < N; j++)
    {
        if(arr[j] > secondLargest && arr[j] != largest)
        {
            secondLargest = arr[j];
        }
    }

    return secondLargest;
}

template <size_t N>
int findSecondLargestOptimal(int (&arr)[N])
{
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < N; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

template <size_t N>
int findSecondSmallestOptimal(int (&arr)[N])
{
    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (int i = 1; i < N; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
    }

    return secondSmallest;
}