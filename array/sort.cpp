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

// bubble sort

void Sort(struct Array *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {

        for (int j = 0; j < length - 1; j++)
        {
            if (arr->A[j] > arr->A[j + 1])
            {
                int temp = arr->A[j];
                arr->A[j] = arr->A[j + 1];
                arr->A[j + 1] = temp;
            }
        }
    }
}

void RSort(struct Array *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {

        for (int j = 0; j < length - 1; j++)
        {
            if (arr->A[j] < arr->A[j + 1])
            {
                int temp = arr->A[j];
                arr->A[j] = arr->A[j + 1];
                arr->A[j + 1] = temp;
            }
        }
    }
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
    RSort(&arr, arr.length);
    // after sort
    cout << endl;
    Display(arr);

    return 0;
}