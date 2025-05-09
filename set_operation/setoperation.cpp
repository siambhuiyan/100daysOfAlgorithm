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

int main()
{
    int *a = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *b = new int[5]{11, 12, 13, 14, 15};
    int length = 0;

    int *d = Union(a, b, 10, 5, length);
    cout << length << endl;

    for (int i = 0; i < length; i++)
        cout << d[i] << " ";

    delete[] a;
    delete[] b;
    delete[] d;
    return 0;
}