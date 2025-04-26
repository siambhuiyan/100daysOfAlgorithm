#include <iostream>

using namespace std;

int main()
{
    // all the variable stores in stack
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11}};
    // partail stack partial heap
    int *b[3];

    b[0] = new int[4];
    b[1] = new int[4];
    b[2] = new int[4];

    // all stores in heap
    int **c; // it stores in the stack
    c = new int *[3];
    c[0] = new int[4];
    c[1] = new int[4];
    c[2] = new int[4];

    return 0;
}