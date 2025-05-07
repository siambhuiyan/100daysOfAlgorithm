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

void Display(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
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

// concat
// true -> a concat b
int *Concat(int *a, int *b, int lengthA, int lengthB, bool aTob)
{
    int size = lengthA + lengthB;
    cout << size << endl;
    int *arr = new int[size];
    int cur = 0;
    if (aTob == true)
    {
        for (int i = 0; i < lengthA; i++)
        {
            arr[i] = a[i];
            cur++;
        }
        int j = 0;
        // cout << cur << endl;
        for (int i = cur; i < size; i++)
        {
            arr[i] = b[j++];
        }
    }
    else
    {
        for (int i = 0; i < lengthB; i++)
        {
            arr[i] = b[i];
            cur++;
        }
        for (int i = cur; i < size; i++)
        {
            arr[i] = a[i];
        }
    }

    return arr;
}
// compare
// copy

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
    bool isSuccess = appendD(&arr, num, 3);
    cout << endl
         << isSuccess << endl;
    // after sort
    cout << endl;
    Display(arr);
    cout << endl;
    cout << arr.length;

    // arrays
    int a[3] = {1, 2, 3};
    int b[5] = {3, 4, 5, 6, 7};
    cout << endl
         << "Concat: --->" << endl;
    int *concatArr = Concat(a, b, 3, 5, true);
    Display(concatArr, 8);

    delete[] concatArr;
    return 0;
}
