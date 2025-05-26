#include <iostream>
using namespace std;

bool checkDiagonal(int a[][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (a[i][j] != 0 && i != j)
            {
                return false;
            }
        }
    }
    return true;
}

void set(int *b, int i, int j, int x)
{
    if (i == j)
    {
        b[i - 1] = x;
    }
}

int get(int a[], int i, int j)
{
    if (i == j)
    {
        return a[i - 1];
    }
    return -1;
}

int main()
{
    int a[][3] = {{1, 0, 0}, {0, 3, 0}, {0, 0, 5}};
    bool isDiagonal = checkDiagonal(a);
    if (isDiagonal)
        cout << "It is a diagonal matrix" << endl;
    else
        cout << "Not a diagonal" << endl;

    int d[3];
    set(d, 1, 1, 1);
    set(d, 2, 2, 3);
    set(d, 3, 3, 5);

    cout << "Value is : " << get(d, 2, 2);
    return 0;
}