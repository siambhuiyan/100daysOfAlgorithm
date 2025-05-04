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

void LShift(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
}

void LRotate(struct Array *arr)
{
    int first = arr->A[0];
    LShift(arr);
    arr->length++;
    arr->A[arr->length--] = first;
}

void RShift(struct Array *arr)
{
    for (int i = arr->length - 1; i > 0; i--)
    {

        arr->A[i] = arr->A[i - 1];
    }
    LShift(arr);
}

int main()
{

    struct Array arr = {
        {9, 8, 7, 5, 4, 3, 2, 1, 7},
        9,
        20,
    };

    Display(arr);
    cout << endl;
    RShift(&arr);
    Display(arr);

    cout << endl;
    LRotate(&arr);
    Display(arr);

    return 0;
}