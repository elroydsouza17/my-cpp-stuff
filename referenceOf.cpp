#include <iostream>

using namespace std;

int main()
{
    
    int a = 12;
    int b = 13;
    int& r1 = a;
    int& r2 = b;
    
    cout << a << endl;
    cout << b << endl;
    cout << r1 << endl;
    cout << r2 << endl;

    cout << &a << endl;
    cout << &b << endl;

    r1 = r2;
    cout << r1 << endl;
    cout << r2 << endl;

    cout << a << endl;
    cout << b << endl;

    return 0;


}