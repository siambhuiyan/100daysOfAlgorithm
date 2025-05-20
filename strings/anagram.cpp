#include <iostream>
using namespace std;

void anagramCheck(char a[], char b[])
{
    bool found;
    for (int i = 0; a[i] != '\0'; i++)
    {
        found = true;
        for (int j = 0; b[j] != '\0'; j++)
        {
            if (a[i] != b[j] && b[j + 1] == '\0')
            {
                found = false;
                break;
            }
        }
        if (!found)
            break;
    }
    if (found)
        cout << "It is an anagram" << endl;
    else
        cout << "It is not an anagram" << endl;
}

int main()
{
    char a[] = "decimal";
    char b[] = "medical";
    anagramCheck(a, b);
    return 0;
}