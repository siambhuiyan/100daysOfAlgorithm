#include <iostream>
using namespace std;

int length(char name[])
{
    int count = 0;
    int i = 0;
    while (name[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
    char name[] = "siam";
    cout << length(name);
    return 0;
}