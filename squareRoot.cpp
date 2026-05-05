#include <iostream>

using namespace std;

double square(double number)
{
    return number * number;
}

void printSquare(int number)
{
    cout << "The square root of "<<number<<" is "<<square(number)<<"\n";
}

int main()
{
    printSquare(45);
}