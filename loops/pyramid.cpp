#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int space = n - 1; space > i; space--)
        {
            cout << " ";
        }
        // number
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }

        // second pyramid
        for (int k = i; k > 0; k--)
        {
            cout << k;
        }

        cout << endl;
    }
    return 0;
}
