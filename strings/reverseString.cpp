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

char *reverse(char a[])
{

    int length = len(a);
    char *temp = new char[length + 1];
    int i = 0;
    temp[length] = '\0';
    while (a[i] != '\0')
    {
        temp[length - 1 - i] = a[i];
        i++;
    }

    return temp;
}

int main()
{
    char name[] = "siamdfkl";
    char *revString = reverse(name);
    cout << revString << endl;
    int i = 0;
    while (revString[i] != '\0')
    {
        cout << revString[i] << endl;
        i++;
    }
    return 0;
}