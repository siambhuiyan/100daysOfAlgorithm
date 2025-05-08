#include <iostream>
using namespace std;

int len(int *a)
{
    int count = 0;
    while (a[count] != -1)
        count++;
    return count;
}

bool Compare(int *a, int *b)
{
    int lenA = len(a);
    int lenB = len(b);
    if (lenA != lenB)
        return false;

    for (int i = 0; i < lenA; i++)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

int main()
{
    int *a = new int[5]{1, 2, 3, 4, -1};
    int *b = new int[5]{1, 2, 3, 4, -1};

    bool isSame = Compare(a, b);
    if (isSame)
        cout << "Both Array contain same values";
    else
        cout << "No similarities";

    return 0;
}