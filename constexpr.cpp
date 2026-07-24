#include <iostream>

int addtwo(int x);

int main()
{
    int a = 1;
    const int b = addtwo(b);
    // constexpr int c = b; this will give an error too
    // b = addtwo(b); will give error for const
}

int addtwo(int x)
{
    return x + 2;
}