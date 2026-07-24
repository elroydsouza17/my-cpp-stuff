#include <iostream>

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i != 7; i++)
    {
        std::cout << array[i] << std::endl;
    }

    // copies each value of array in x
    for (auto x: array)
    {
        std::cout << x << std::endl;
    }

    // takes reference of array in x and increments it .
    for (auto &x: array)
    {

        std::cout << x << std::endl;
        x++;
    }
}

