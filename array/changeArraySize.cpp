#include <iostream>
using namespace std;

int main()
{
    int originalSize = 5;
    int newSize = 10;

    int *arr = new int[originalSize];

    // fill the original array with elements
    for (int i = 0; i < originalSize; ++i)
    {
        arr[i] = i * 10;
    }

    // Create new bigger array
    int *newArr = new int[newSize];

    // copy elements
    for (int i = 0; i < originalSize; ++i)
    {
        newArr[i] = arr[i];
    }

    // free old array
    delete[] arr;

    // now use newArr as the bigger array
    arr = newArr;

    // fill new elements
    for (int i = originalSize; i < newSize; ++i)
    {
        arr[i] = i * 10;
    }

    // print new array
    for (int i = 0; i < newSize; ++i)
    {
        cout << arr[i] << " ";
    }

    // clean up
    delete[] arr;
}