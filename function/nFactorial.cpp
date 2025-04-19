#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n;
    cout << "Please enter the value you want to find factoiral for: ";
    cin >> n;
    int fact = factorial(n);
    cout << "factorial of " << n << " is " << fact;
    return 0;
}