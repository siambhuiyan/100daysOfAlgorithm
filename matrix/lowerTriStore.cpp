#include <iostream>
using namespace std;

// total of first k nattural numbers (n-1)*n/2

class StoreLowerTri
{
private:
    int n;
    int *a;

public:
    StoreLowerTri(int n)
    {
        this->n = n;
        a = new int[n * (n + 1) / 2];
    }
    ~StoreLowerTri()
    {
        delete[] a;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void StoreLowerTri::set(int i, int j, int x)
{

    if (i >= j)
    {
        a[(((i - 1) * i) / 2) + (j - 1)] = x;
    }
    else
    {
        cout << "not a valid operation" << endl;
    }
}

int StoreLowerTri::get(int i, int j)
{
    if (i >= j)
    {
        return a[((i - 1) * i) / 2 + (j - 1)];
    }
    else
    {
        return -999;
    }
}

void StoreLowerTri::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << a[((i * (i - 1)) / 2) + (j - 1)] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    StoreLowerTri lowerD(3);
    lowerD.set(1, 1, 1);
    lowerD.set(2, 1, 2);
    lowerD.set(2, 2, 3);
    lowerD.set(3, 1, 4);
    lowerD.set(3, 2, 5);
    lowerD.set(3, 3, 6);

    int value = lowerD.get(3, 3);
    cout << "value: " << value << endl;
    lowerD.display();
    return 0;
}