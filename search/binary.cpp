#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

// binary search
int BinarySearch(struct Array *arr, int value)
{
    int low = 0;
    int high = arr->length - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr->A[mid] == value)
            return mid;
        else if (arr->A[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

// recursive binary search
int BinaryRecursive(struct Array *arr, int value, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr->A[mid] == value)
            return mid;
        else if (arr->A[mid] > value)
            return BinaryRecursive(arr, value, low, mid - 1);
        else
            return BinaryRecursive(arr, value, mid + 1, high);
    }
    return -1;
}

int main()
{
    struct Array arr =
        {
            {2, 3, 4, 5, 6, 7, 8, 9, 10},
            20,
            9,
        };
    cout << BinarySearch(&arr, 8);
    cout << endl;
    cout << "Recursive Binary Search " << endl;
    cout << BinaryRecursive(&arr, 10, 0, arr.length - 1);
    cout << endl;
    return 0;
}