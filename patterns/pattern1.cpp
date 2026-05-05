#include <iostream>

using namespace std;

void printPattern1(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern2(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern3(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << ""<<j + 1<<" ";
        }
        cout << endl;
    }
}

void printPattern4(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << i <<" ";
        }
        cout << endl;
    }
}

void printPattern5(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n + 1) - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern6(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n + 1) - i; j++)
        {
            cout << j <<" ";
        }
        cout << endl;
    }
}

void printPattern7(int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i + count; j++)
        {
            cout << "* ";
        }
        count ++;
        cout << endl;
    }
}

void printPattern7Optimal(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (2 * i) - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern8(int n)
{

    for(int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= (2 * i) - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printPattern9(int n)
{

    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        for(int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "* ";
        }

        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }
}

void printPattern10(int n)
{

    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "  ";
        }

        for(int j = 1; j <= 2 * n - (2 * i - 1); j++)
        {
            cout << "* ";
        }

        for (int j = 1; j <= i - 1; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }
}


void printPattern11(int n)
{

    // part 1
    for(int i = 1; i <= (n / 2); i++)
    {   
        for (int j = 1; j <= (n / 2) - i; j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= (2 * (i) - 1); j++)
        {
            cout << "* ";
        }

        for (int j = i; j <= (n / 2) - i; j++)
        {
            cout << "  ";
        }
        cout << endl;
    }


    //part 2
    for(int i = 1; i <= (n / 2); i++)
    {   
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "  ";
        }

        for(int j = 1; j <= n - (2 * i) + 1; j++)
        {
            cout << "* ";
        }


        for (int j = 1; j <= i - 1; j++)
        {
            cout << "  ";
        }

        cout << endl;
    }
}

int main()
{
    printPattern11(6);
}