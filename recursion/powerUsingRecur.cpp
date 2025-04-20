#include <iostream>
using namespace std;

int powN(int m, int times)
{
    if (times == 0)
        return 1;

    if (m == 0)
        return 0;

    if (times == 1)
    {
        return m;
    }

    return powN(m, times - 1) * m;
}

int main()
{
    int m = 2;
    int times = 5;
    cout << powN(m, times) << endl;
    return 0;
}