#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int size;
    int value;
    int i = 0;
    bool found = false;

    cout << "Enter size of array list: ";
    cin >> size;

    cout << "Enter values: ";

    for(i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter value to search: ";
    cin >> value;

    i = 0;

    while(i < size)
    {
        if(arr[i] == value)
        {
            found = true;
            break;
        }

        i++;
    }

    if(found)
    {
        cout << "Value found at index " << i;
    }
    else
    {
        cout << "Value not found.";
    }

    return 0;
}