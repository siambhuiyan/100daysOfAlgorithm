#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Reverse(struct Array *arr, int length)
{
    int len = length - 1;
    for (int i = 0; i < length / 2; i++)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[len];
        arr->A[len] = temp;
        len--;
    }
}

void ReverseW(struct Array *arr, int length)
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        int temp = arr->A[start];
        arr->A[start] = arr->A[end];
        arr->A[end] = temp;

        start++;
        end--;
    }
}

void Display(struct Array arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

int main()
{
    int length;
    length = 5;
    struct Array arr = {{8, 2, 4, 2, 6}, 10, 20};
    Display(arr, length);

    cout << endl;
    Reverse(&arr, length);
    cout << endl;

    Display(arr, length);

    return 0;
}