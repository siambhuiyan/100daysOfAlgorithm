#include <iostream>
using namespace std;

int countVowels(char word[])
{
    int i = 0;
    int count = 0;
    while (word[i] != '\0')
    {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
        {
            count++;
        }
        i++;
    }
    return count;
}

int countConsonent(char word[])
{
    int i = 0;
    int count = 0;
    while (word[i] != '\0')
    {
        if (word[i] != 'a' || word[i] != 'e' || word[i] != 'i' || word[i] != 'o' || word[i] != 'u' ||
            word[i] != 'A' || word[i] != 'E' || word[i] != 'I' || word[i] != 'O' || word[i] != 'U')
        {
            count++;
        }
        i++;
    }
    return count;
}

int main()
{
    char name[] = "siam al asad";
    cout << countVowels(name);
    cout << endl
         << countConsonent(name);
    return 0;
}