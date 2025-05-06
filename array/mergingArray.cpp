#include <iostream>
using namespace std;

struct Array
{
    int *A;
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

// append - add array b to the end of the array a
void append(struct Array *arrA, int b[], int bLength)
{
    if ((arrA->size - arrA->length) < bLength)
    {
        cout << "Failed to append: not enough space";
        return;
    }

    for (int i = 0; i < bLength; i++)
        arrA->A[arrA->length++] = b[i];
}

// dynamically allocate if not enough memory
bool appendD(struct Array *arr, int b[], int bLength)
{
    if ((arr->size - arr->length) < bLength)
    {
        int newSize = arr->size + bLength;
        int *newArray = new int[newSize];
        for (int i = 0; i < arr->length; i++)
        {
            newArray[i] = arr->A[i];
        }

        delete[] arr->A;
        arr->A = newArray;
        arr->size = newSize;
    }

    for (int i = 0; i < bLength; i++)
    {
        arr->A[arr->length++] = b[i];
    }
    return true;
}

int main()
{

    struct Array arr;
    arr.size = 10;
    arr.length = 5;
    arr.A = new int[arr.size];

    // Set initial values
    arr.A[0] = 10;
    arr.A[1] = 50;
    arr.A[2] = 20;
    arr.A[3] = 30;
    arr.A[4] = 40;

    int num[3] = {1, 2, 3};

    // before sort
    Display(arr);
    cout << endl;
    appendD(&arr, num, 3);
    // after sort
    cout << endl;
    Display(arr);
    cout << endl;
    cout << arr.length;

    return 0;
}