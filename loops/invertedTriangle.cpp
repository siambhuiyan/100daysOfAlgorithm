#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    char init = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int space = 0; space < i; space++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << init;
        }
        cout << endl;
        init++;
    }
    return 0;
}
