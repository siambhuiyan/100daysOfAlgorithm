#include <iostream>
using namespace std;

class Hash
{
private:
    int *arr;
    int size;
    int length;

public:
    Hash(int s)
    {
        size = s;
        length = 0;
        arr = new int[s];
    }

    // destructure
    ~Hash()
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

    // method -> hash table check duplicate
    void hashCheck(int h)
    {
        int temp[h + 1] = {};
        for (int i = 0; i < length; i++)
        {
            temp[arr[i]]++;
        }

        // print the number of times return
        for (int i = 0; i <= h; i++)
        {
            cout << i << " appeared for " << temp[i] << endl;
        }
    }
};

int main()
{
    Hash hash(10);
    hash.add(1);
    hash.add(1);
    hash.add(1);
    hash.add(3);
    hash.add(3);
    hash.add(2);

    hash.display();

    hash.hashCheck(3);

    return 0;
}