#include <iostream>

using namespace std;

void printNumbersLinearly(int i, int n)
{
    if (i > n) return;
    cout << i << endl;
    printNumbersLinearly(i + 1, n);
}

void printNumbersReverse(int i, int n)
{
    if(i > n) return;
    cout << n - i + 1 << endl;
    printNumbersReverse(i + 1, n);
}

void printNumbersReverse2(int i, int n)
{
    if(i < 1) return;
    cout << i << endl;
    printNumbersReverse2(i - 1, n);
}

void printNumbersLinearlyBackTrack(int i, int n)
{
    if( i < 1) return;
    printNumbersLinearlyBackTrack(i - 1, n);
    cout << i << endl;
}

void printNumbersReverseBackTrack(int i, int n)
{
    if( i > n ) return;
    printNumbersReverseBackTrack(i + 1, n);
    cout << i << endl;
}


int main()
{   
// printNumbersLinearly(1, 5);
// printNumbersReverse(1, 5);
// printNumbersReverse2(5, 5);
    printNumbersReverseBackTrack(1, 5);
}