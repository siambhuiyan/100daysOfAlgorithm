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

void SortedInsert(struct Array *arr, int value)
{
    for (int i = arr->length - 1; i >= 0; i--)
    {
        if (arr->A[i] > value)
        {
            arr->A[i + 1] = arr->A[i];
            arr->A[i] = value;
        }
        else
        {
            arr->A[i] = value;
        }
    }
    arr->length++;
}

int main()
{

    struct Array arr = {
        {9, 8, 7, 5, 4, 3, 2, 1, 7},
        9,
        20,
    };

    // before sort
    Display(arr);
    cout << endl;
    SortedInsert(&arr, 20);
    // after sort
    cout << endl;
    Display(arr);

    return 0;
}