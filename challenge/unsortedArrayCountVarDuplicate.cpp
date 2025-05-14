#include <iostream>
using namespace std;

class CountApproach
{
private:
    int *arr;
    int size;
    int length;

public:
    CountApproach(int s)
    {
        size = s;
        length = 0;
        arr = new int[s];
    }

    // destructure
    ~CountApproach()
    {
        delete[] arr;
    }

    // method -> add
    void add(int value)
    {
        if (size > length)
        {
            arr[length++] = value;
        }
        return;
    }

    // method -> display
    void display()
    {
        if (length > 0)
        {
            for (int i = 0; i < length; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    // track the count variable to find duplicate with count variable
    void countDuplicate()
    {

        for (int i = 0; i < length; i++)
        {

            if (arr[i] != -1)
            {
                int count = 1;
                for (int j = i + 1; j < length; j++)
                {
                    if (arr[i] == arr[j])
                    {
                        count++;
                        arr[j] = -1;
                    }
                }
                if (count > 1)
                    cout << arr[i] << " appears for " << count << " times." << endl;
            }
        }
    }
};

int main()
{
    CountApproach duplicate(10);
    duplicate.add(2);
    duplicate.add(4);
    duplicate.add(1);
    duplicate.add(2);
    duplicate.add(1);
    duplicate.add(3);
    duplicate.add(4);

    duplicate.display();
    duplicate.countDuplicate();

    return 0;
}