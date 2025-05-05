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

bool CheckSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    struct Array arr = {
        {10, 50, 20, 30, 40},
        5,
        20,
    };

    // before sort
    Display(arr);
    cout << endl;
    cout << CheckSorted(arr);
    // after sort
    cout << endl;
    Display(arr);

    return 0;
}