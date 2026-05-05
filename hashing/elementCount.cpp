#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    
    int arr[n];

    // take input to array.
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }


    // create hash
    int max;
    cout << "Enter max number in array" << endl;
    cin >> max;
    int hash[max + 1] = {0};

    // precompute 
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1; 
    }

    for(int i = 0; i < max + 1; i++)
    {
        cout << hash[i] << endl;
    }
}