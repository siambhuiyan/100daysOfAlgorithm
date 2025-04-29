#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout << "\nElements are\n";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

// append to the array
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x; // use the current value to append
                                   // then increase the length
    }
}

// insert to the array
void Insert(struct Array *arr, int index, int ele)
{
    if (arr->length < arr->size || index >= 0 || index <= arr->length)
    {
        for (int i = arr->length + 1; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = ele;
        arr->length++;
    }
    else
    {
        cout << "insert failed" << endl;
    }
}

// delete from array
void Delete(struct Array *arr, int index)
{
    if (index >= 0 || index <= arr->length)
    {
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

// linear search
int linearSearch(struct Array *arr, int value)
{
    // if found will return the index number

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// swap value
void Swap(struct Array *arr, int replaceWith, int replaceFor)
{
    int temp = arr->A[replaceWith];
    arr->A[replaceWith] = arr->A[replaceFor];
    arr->A[replaceFor] = temp;
}

// improved linear search
int linearSearchImproved(struct Array *arr, int value)
{
    if (arr->A[0] == value)
        return 0;
    for (int i = 1; i < arr->length; i++)
    {
        if (arr->A[i] == value)
        {
            Swap(arr, i, i - 1);
            return i - 1;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    Insert(&arr, 2, 200);
    Append(&arr, 20);
    Delete(&arr, 2);

    Display(arr);

    cout << endl;
    cout << linearSearch(&arr, 20);
    cout << endl;
    cout << linearSearch(&arr, 0);
    Swap(&arr, 2, 3);
    Display(arr);

    cout << endl;
    cout << "Improved Search with swap" << endl;

    cout << linearSearchImproved(&arr, 20);
    cout << linearSearchImproved(&arr, 20);
    cout << linearSearchImproved(&arr, 20);
    cout << linearSearchImproved(&arr, 20);
    cout << linearSearchImproved(&arr, 20);

    Display(arr);

    return 0;
}