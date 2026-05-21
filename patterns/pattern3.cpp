#include <iostream>

using namespace std;

void printPattern(int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (i + j + 1) % 2 << " ";
        }

        cout << endl;
    }
}

int main()
{
    printPattern(7);
}

