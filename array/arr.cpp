#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 4};
    cout << sizeof(arr) / sizeof(int) << endl;

    int arr1[5];
    arr1[1] = 12;
    arr[0] = 13;
    cout << arr1[2] << endl;
    return 0;
}