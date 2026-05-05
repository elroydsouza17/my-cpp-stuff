#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char arr[] = "this is a test";

    for(int i = 0; i < strlen(arr); i++)
    {
        cout << arr[i] << endl;
    }

    // precompute 
    int hash[26] = {0};

    for(int i = 0; i < strlen(arr); i++)
    {
        hash[arr[i] - 97] += 1;
    }

    //print hash table
    for(int i = 0; i < 26; i++)
    {
        cout << hash[i] << endl;
    }
}