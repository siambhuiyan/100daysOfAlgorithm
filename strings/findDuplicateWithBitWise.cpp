#include <iostream>
using namespace std;

// masking
void masking(int value, int mask)
{
    // int value = 0b0101;
    // int mask = 0b0001;

    int result = value & mask;

    if (result)
    {
        cout << "Last bit is on" << endl;
    }
}

void findDupUsingMasking(char a[])
{
    long int h = 0, x = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        x = 1;
        x = x << (a[i] - 97);
        if ((x & h) > 0)
        {
            cout << "Duplicate found for : " << a[i] << endl;
        }
        else
        {
            h = x | h;
        }
    }
}

int main()
{
    int value = 0b0101;
    int mask = 0b0001;
    masking(value, mask);
    char a[] = "Finding";
    findDupUsingMasking(a);

    return 0;
}