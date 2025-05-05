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
    if (arr->length >= arr->size)
    {
        cout << "Insertion failed : Array is full\n";
        return;
    }
    for (int i = arr->length - 1; i >= 0; i--)
    {
        if (value > arr->A[i])
        {
            arr->A[i + 1] = value;
            arr->length++;
            return;
        }
        else
        {
            arr->A[i + 1] = arr->A[i];
        }

        if (i == 0)
        {
            arr->A[0] = value;
            arr->length++;
            // the pblm with this is that loop should only shift
            // it is not the job of the loop to insert.
        }
    }
}

// solution 1
void whileInsert(struct Array *arr, int value)
{
    if (arr->length >= arr->size)
    {
        cout << "not enough space" << endl;
        return;
    }
    int i = arr->length - 1;
    // just shift if the value is lower than the current index value
    while (i >= 0 && arr->A[i] > value)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
    arr->length++;
}

// solution 2 no duplicate
void noDuplicateInsert(struct Array *arr, int value)
{
    if (arr->length >= arr->size)
    {
        return;
    }
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > value)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    // now check for duplicate
    if (i >= 0 && arr->A[i] == value)
    {
        return;
    }

    arr->A[i + 1] = value;
    arr->length++;
}
void SortedInsertUnique(struct Array *arr, int value)
{
    if (arr->length >= arr->size)
        return;

    int i = arr->length - 1;

    while (i >= 0 && arr->A[i] > value)
        arr->A[i + 1] = arr->A[i--];

    if (i >= 0 && arr->A[i] == value)
    {
        printf("Value already exists\n");
        return; // Prevent duplicates
    }

    arr->A[i + 1] = value;
    arr->length++;
}

int main()
{

    struct Array arr = {
        {10, 20, 30, 40},
        4,
        20,
    };

    // before sort
    Display(arr);
    cout << endl;
    SortedInsertUnique(&arr, 10);
    // after sort
    cout << endl;
    Display(arr);

    return 0;
}