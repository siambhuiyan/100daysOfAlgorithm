#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int length;
    int size;

    // Resize function: doubles the size
    void resize()
    {
        int newSize = size * 2;
        int *newArr = new int[newSize];

        for (int i = 0; i < length; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size = newSize;
    }

public:
    // constructor
    DynamicArray(int s)
    {
        size = s;
        length = 0;
        arr = new int[s];
    }

    // destructor
    ~DynamicArray()
    {
        delete[] arr;
    }

    // add element
    void add(int value)
    {
        if (length < size)
            arr[length++] = value;

        else
        {
            resize();
            arr[length++] = value;
        }

        // cout << "Array out of space!";
    }

    // display elements
    void display()
    {
        if (length <= 0)
        {
            cout << "There is nothing to display. Please add an element!";
            return;
        }
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    // getter
    int getLength()
    {
        return length;
    }
    // setter
    //  void setLength(int len){
    //      length = len;
    //  }

    // getter for size
    int getSize()
    {
        return size;
    }
    // delete the last element
    void pop()
    {
        if (length >= 0)
        {
            length--;
        }
        else
        {
            cout << "Array is empty\n";
        }
    }

    // find the mising element
    int findM()
    {
        int n = length + 1;
        // n*(n+1)/2 -> this is a formula for finding the total of n ele
        int ExpectTotal = n * (n + 1) / 2;
        int sumOfArr = 0;
        for (int i = 0; i < length; i++)
            sumOfArr += arr[i];

        return ExpectTotal - sumOfArr;
    }

    // find mising element when it starts from anywhere and sorted
    int findO()
    {
        int low = arr[0];
        // int high = arr[length - 1];
        int diff = low - 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] - i != diff)
            {
                return diff + i;
            }
        }
        return -1;
    }

    int *findAll(int &len)
    {
        int *newArr = new int[length];
        int newLen = 0;

        int low = arr[0];
        int diff = low - 0;

        // logic
        for (int i = 0; i < length; i++)
        {

            if (arr[i] - i != diff)
            {
                newArr[newLen++] = diff + i;
                diff = arr[i] - i;
            }
        }
        len = newLen;
        return newArr;
    }
};

int main()
{
    DynamicArray arr(5);
    arr.add(1);
    arr.add(2);
    arr.add(4);
    arr.add(5);

    cout << "Mising value : " << arr.findM() << endl;

    // dynamic array allocation
    DynamicArray *arr1 = new DynamicArray(10);
    arr1->add(12);
    arr1->add(14);
    arr1->add(15);
    arr1->add(17);
    arr1->add(19);

    cout << arr1->findO() << endl;
    cout << "All the missing values: " << endl;
    int len = 0;
    int *newArr = arr1->findAll(len);
    cout << "length: " << len << endl;
    ;
    for (int i = 0; i < len; i++)
    {
        cout << "M:" << newArr[i] << " ";
    }

    cout << endl;

    // display array
    arr1->display();

    // display array
    arr.display();

    // clean the memory
    delete arr1;
    delete[] newArr;
    return 0;
}