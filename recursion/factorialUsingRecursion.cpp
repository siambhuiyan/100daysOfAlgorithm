#include <iostream>
using namespace std;

int factorialN(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    if (n < 0)
        return -1;

    return factorialN(n - 1) * n;
};

int main()
{
    int n = 0;
    cout << factorialN(n) << endl;
    return 0;
}