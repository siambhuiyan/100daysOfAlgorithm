#include <iostream>
using namespace std;

class PairWithSum
{
private:
    int *arr;
    int size;
    int length;

public:
    PairWithSum(int s)
    {
        size = s;
        length = 0;
        arr = new int[s];
    }

    // destructure
    ~PairWithSum()
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

    // find a pair with sum k (a+b =k)

    void findPair(int sum)
    {
        for (int i = 0; i < length; i++)
        {
            int b = sum - arr[i];
            for (int j = i + 1; j < length; j++)
            {
                if (b == arr[j])
                {
                    cout << "a : " << arr[i] << " + b : " << arr[j] << " = " << arr[i] + arr[j] << ". And index of a and b : " << i << " " << j << endl;
                    break;
                }
            }
        }
    }
};

int main()
{
    PairWithSum duplicate(10);
    duplicate.add(2);
    duplicate.add(4);
    duplicate.add(1);
    duplicate.add(2);
    duplicate.add(1);
    duplicate.add(3);
    duplicate.add(4);

    duplicate.display();
    duplicate.findPair(4);

    return 0;
}