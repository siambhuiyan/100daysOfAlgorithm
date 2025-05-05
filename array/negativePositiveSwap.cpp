#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int size;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

void swap(struct Array *arr, int swapToI, int swapFromJ)
{
    int temp = arr->A[swapToI];
    arr->A[swapToI] = arr->A[swapFromJ];
    arr->A[swapFromJ] = temp;
}

void allNegativeLeft(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;

        if (i < j)
        {
            swap(arr, i, j);
        }
    }
}

int main()
{

    struct Array arr = {
        {10, 50, -20, -30, 40},
        5,
        20,
    };

    // before sort
    Display(arr);
    cout << endl;
    allNegativeLeft(&arr);
    // after sort
    cout << endl;
    Display(arr);

    return 0;
}