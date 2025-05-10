#include <iostream>
using namespace std;

// for sorted item
int *Union(int *a, int *b, int lengthA, int lengthB, int &resultLength)
{
    int i = 0, k = 0, j = 0;
    int length = lengthA + lengthB; // max possible size
    int *uniA = new int[length];

    while (i < lengthA && j < lengthB)
    {
        if (a[i] > b[j])
            uniA[k++] = b[j++];
        else if (a[i] == b[j])
        {
            uniA[k++] = a[i++];
            j++;
        }
        else
            uniA[k++] = a[i++];
    }

    while (i < lengthA)
        uniA[k++] = a[i++];
    while (j < lengthB)
        uniA[k++] = b[j++];

    resultLength = k;

    return uniA;
};

// intersection
int *Intersection(int *a, int *b, int lengthA, int lengthB, int &resultL)
{
    int i = 0, j = 0, k = 0;
    int len = lengthA >= lengthB ? lengthA : lengthB;
    // new array
    int *arr = new int[len];

    while (i < lengthA && j < lengthB)
    {
        if (a[i] == b[j])
        {
            arr[k] = a[i];
            j++;
            i++;
            k++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    resultL = k;
    return arr;
}

// difference

// compare a[i] against b[j] if the element is less than b then copy to
// new array
// if equal move bot i and j
// a[i]>a[j] move j to the right or other way around a[i]<a[j] move j to
// the left

int main()
{
    int *a = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *b = new int[5]{11, 12, 13, 14, 15};
    int length = 0;

    int *d = Union(a, b, 10, 5, length);
    cout << length << endl;

    for (int i = 0; i < length; i++)
        cout << d[i] << " ";

    // intersection
    int *arr1 = new int[5]{1, 2, 3, 4, 5};
    int *arr2 = new int[5]{1, 2, 3, 4, 5};
    int iLen = 0;
    int *e = Intersection(arr1, arr2, 5, 5, iLen);

    cout << endl
         << "Intersection" << endl;
    for (int i = 0; i < iLen; i++)
        cout << e[i] << " ";

    delete[] a;
    delete[] b;
    delete[] d;
    delete[] arr1;
    delete[] arr2;
    delete[] e;
    return 0;
}