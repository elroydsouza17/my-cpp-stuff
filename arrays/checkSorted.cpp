#include <iostream>

using namespace std;

template<size_t N>
void checkIfSorted(int (&arr)[N]);

int main()
{
    int array []= {2, 3, 5, 8, 9, 9, 10, 10, 556, 777};
    checkIfSorted(array);

    return 0;
}

template<size_t N>
void checkIfSorted(int (&arr)[N])
{
    for (int i = 0; i < N - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            cout << "Array not sorted" << endl;
            return;
        }
    }

    cout << "Array sorted !!" << endl;
}