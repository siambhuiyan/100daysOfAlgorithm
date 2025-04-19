#include <iostream>
using namespace std;

int fib(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter number for fibonacci: ";
    cin >> n;
    cout << "The Fibonacci is " << fib(n) << endl;
    return 0;
}
