#include <iostream>

using namespace std;

void printName(int i, int n)
{
    if (i == n) return;
    cout << "Elroy " << endl;
    printName(i + 1, n);
}

int main()
{
    printName(0, 5);
}