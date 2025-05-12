#include <iostream>
using namespace std;

class Operations
{
private:
    int *arr;
    int size;
    int length;

public:
    Operations(int s)
    {
        size = s;
        length = 0;
        arr = new int[size];
    }
    ~Operations()
    {
        delete[] arr;
    }

    int getSize()
    {
        return size;
    }

    int getLength()
    {
        return length;
    }

    void add(int ele)
    {
        if (length > size)
        {
            cout << "No space" << endl;
            return;
        }
        arr[length++] = ele;
    }

    int highest()
    {
        int h = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] >= h)
                h = arr[i];
        }
        return h;
    }

    void checkMatch(int h)
    {
        int *arrDummy = new int[h]();
        for (int i = 0; i < length; i++)
        {
            int value = arr[i];
            arrDummy[value] = 1;
        }

        for (int i = 0; i < h; i++)
        {
            if (arrDummy[i] != 1)
            {
                cout << "M:" << i << " ";
            }
        }
    }
};

int main()
{
    Operations findAll(10);
    findAll.add(2);
    findAll.add(10);

    int h = findAll.highest();

    findAll.checkMatch(h);
    return 0;
}