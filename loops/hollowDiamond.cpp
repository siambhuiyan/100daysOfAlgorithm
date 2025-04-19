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

        // star
        cout << "*";

        // spaces
        if (i != 0)
        {
            for (int k = 2 * i - 1; k > 0; k--)
            {
                cout << " ";
            }
            // star
            cout << "*";
        }

        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        // spaces
        for (int space = 0; space <= i; space++)
        {
            cout << " ";
        }
        // stars
        cout << "*";

        // spaces
        if (i != n - 2)
        {
            for (int j = 0; j < 2 * (n - i) - 5; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
