#include <iostream>
#include <cstring>
using namespace std;

bool isAnagram(char a[], char b[])
{
    int countA[256] = {0};
    int countB[256] = {0};

    // if lengths don't match, not an anagram
    if (strlen(a) != strlen(b))
        return false;

    for (int i = 0; a[i] != '\0'; i++)
    {
        countA[(unsigned char)a[i]]++;
        countB[(unsigned char)b[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (countA[i] != countB[i])
            return false;
    }

    return true;
}
int main()
{
    char a[] = "decimal";
    char b[] = "medical";
    if (isAnagram(a, b))
        cout << "It is an anagram" << endl;
    else
        cout << "It is not an anagram" << endl;

    return 0;
}