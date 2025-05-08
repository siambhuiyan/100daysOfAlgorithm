#include <iostream>
using namespace std;

int *Copy(int *a, int *b, int lengthA, int lengthB)
{
    if (lengthA <= 0 || lengthB <= 0)
        return nullptr;

    int size = lengthA + lengthB;
    int *arr = new int[size];

    // copy array a
    for (int i = 0; i < lengthA; i++)
        arr[i] = a[i];

    // copy array b
    for (int i = 0; i < size; i++)
        arr[lengthA + i] = b[i];

    return arr;
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    int b[6] = {5, 6, 7, 8, 9, 10};
    int *combineArr = Copy(a, b, 4, 6);

    if (combineArr != nullptr)
        for (int i = 0; i < 10; i++)
            cout << combineArr[i] << " ";

    delete[] combineArr;

    return 0;
}