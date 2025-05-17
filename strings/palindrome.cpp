#include <iostream>
using namespace std;

int len(char a[])
{
    int i = 0;
    int tmepLen = 0;
    while (a[i] != '\0')
    {
        tmepLen++;
        i++;
    }

    return tmepLen;
}

bool isPalindrome(char a[])
{
    int i = 0;
    int j = len(a) - 1;
    cout << j;
    while (i <= j)
    {
        if (a[i] != a[j])
        {
            return false;
        }
        j--;
        i++;
    }

    return true;
}

int main()
{
    char a[] = "heh";
    bool isPalin = isPalindrome(a);
    if (isPalin)
    {
        cout << "It is a palindrom" << endl;
    }
    else
    {
        cout << "Not a palindrom" << endl;
    }

    return 0;
}