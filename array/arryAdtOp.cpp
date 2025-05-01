#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

//---------------------------- ARRAY OPERATION ---------------------------

// display
void display(struct Array arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

// get the value
int get(struct Array arr, int length, int index)
{
    if (index >= 0 && index < length)
    {

        return arr.A[index];
    }
    return -1;
}

// set the value
int set(struct Array *arr, int value, int index)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
        return 1;
    }
    return -1;
}

// find the max value
int max(struct Array arr, int length)
{
    int max = -1;
    for (int i = 0; i < length; i++)
    {
        if (max <= arr.A[i])
            max = arr.A[i];
    }
    return max;
}

// find the min value
int min(struct Array arr, int length)
{
    int min = arr.A[0];
    for (int i = 0; i < length; i++)
    {
        if (min > arr.A[i])
            min = arr.A[i];
    }
    return min;
}

// sum of all the array
int sum(struct Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }
    return total;
}

int main()
{
    struct Array arr = {
        {1, 2, 3, 4, 5, 6, 17},
        20,
        7,
    };

    cout << get(arr, arr.length, -13) << endl;
    cout << set(&arr, 11, 5) << endl;
    cout << "Max Value : " << max(arr, arr.length) << endl;
    cout << "Min Value : " << min(arr, arr.length) << endl;
    cout << "Total : " << sum(arr) << endl;

    display(arr, arr.length);

    return 0;
}