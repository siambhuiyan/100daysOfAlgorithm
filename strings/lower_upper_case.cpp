#include <iostream>
using namespace std;

void lowerCase(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] <= 90 && s[i] >= 65)
        {
            s[i] = 32 + s[i];
        }
        i++;
    }
    cout << s;
}

void upperCase(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] - 32;
        }
        i++;
    }

    cout << s;
}

int main()
{
    char name[] = "siam";
    upperCase(name);
    return 0;
}