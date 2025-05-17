#include <iostream>
using namespace std;

// comapare with letters
void compareDuplicate(char a[])
{
    bool isFound = false;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == -1)
            continue;
        int count = 1;
        for (int j = i + 1; a[j] != '\0'; j++)
        {

            if (a[i] == a[j])
            {
                count++;
                a[j] = -1;
            }
        }
        if (count > 1)
        {
            isFound = true;
            cout << "Duplicate found : " << a[i] << " for " << count << " times." << endl;
        }
    }
    if (!isFound)
    {
        cout << "No duplicate found!" << endl;
    }
}

int main()
{
    char a[] = "helllo";
    compareDuplicate(a);
    return 0;
}
