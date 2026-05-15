#include <iostream>
#include <map>

using namespace std;

int main()
{
    int size;
    cout << "Enter array size" << endl;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // calculate first
    map<int, int> mpp;
    for(int i = 0; i < size; i++)
    {
        mpp[arr[i]]++;
    }

    int n;
    cout << "Enter the number of no's be read from map" << endl;
    cin >> n;

    while(n)
    {   
        int number;
        cin >> number;
        cout << mpp[number] << endl;
        n--;
    }
}