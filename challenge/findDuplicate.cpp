#include <iostream>
using namespace std;

class ArrayOp
{
private:
    // properties

    int *arr;
    int size;
    int length;
    bool isSorted;

public:
    ArrayOp(int s, bool isSort)
    {
        arr = new int[s];
        size = s;
        length = 0;
        isSorted = isSort;
    }

    ~ArrayOp()
    {
        delete[] arr;
    }

    // methods
    int getSize()
    {
        return size;
    }
    int getLength()
    {
        return length;
    }

    // add element to the array
    void add(int item)
    {
        if (length > size)
        {
            cout << "Out of space." << endl;
            return;
        }
        arr[length++] = item;
    }

    // display
    void display()
    {
        if (length > 0)
        {
            for (int i = 0; i < length; i++)
                cout << arr[i] << " ";
        }
        return;
    }

    // find dulplicate
    int *duplicateM(int &len)
    {
        if (!isSorted)
            return nullptr;
        int *allDuplicates = new int[length / 2];
        int lastDuplicate = 0;
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
            {
                allDuplicates[j++] = arr[i];
                lastDuplicate = arr[i];
                len++;
            }
        }

        return allDuplicates;
    }

    // count appear
    void count()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                int j = i + 1;
                while (arr[j] == arr[i])
                    j++;
                cout << arr[i] << " appeared for " << j - i << " times" << endl;
                i = j - 1;
            }
        }
    }
};

int main()
{
    ArrayOp obj(10, true);
    obj.add(1),
        obj.add(1);
    obj.add(1);
    obj.add(2);
    cout << obj.getLength() << endl;
    int len = 0;

    int *duplicate = obj.duplicateM(len);
    obj.count();

    for (int i = 0; i < len; i++)
        cout
            << duplicate[i] << " ";

    return 0;
}