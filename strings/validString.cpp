#include <iostream>
using namespace std;

void valid(char msg[])
{
    bool isValid = true;
    for (int i = 0; msg[i] != '\0'; i++)
    {
        if (!((msg[i] >= 65 && msg[i] <= 90) || (msg[i] >= 97 && msg[i] <= 122)))
        {
            isValid = false;
        }
    }

    if (isValid)
    {
        cout << "valid string" << endl;
    }
    else
    {
        cout << "Not a valid string" << endl;
    }
}

int main()
{
    char name[] = "si?am";
    valid(name);
    return 0;
}