#include <iostream>
using namespace std;

bool isLowerTri(int **a, int rows, int cols)
{
    if (rows != cols)
        return false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a[i][j] != 0 && j > i)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int square = 3;
    int **matrix = new int *[square];
    for (int i = 0; i < square; i++)
    {
        matrix[i] = new int[square];
    }

    // fill matrix
    int temp[][square] = {{1, 0, 0},
                          {2, 3, 3},
                          {4, 5, 6}};
    for (int i = 0; i < square; i++)
    {
        for (int j = 0; j < square; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
    bool isL = isLowerTri(matrix, square, square);
    cout << isL;
    return 0;
}