#include <iostream>
using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void Diagonal::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
    else
    {
        cout << "Enter a valid number";
    }
}

int Diagonal::get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return -999;
    }
}

void Diagonal::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << i + 1 << ": " << A[i] << endl;
    }
}

int main()
{
    Diagonal d(5);
    d.set(1, 1, 3);
    d.set(2, 2, 6);
    d.set(3, 3, 7);
    d.set(4, 4, 2);
    d.set(5, 5, 1);

    cout << d.get(2, 2) << endl;

    d.display();

    return 0;
}