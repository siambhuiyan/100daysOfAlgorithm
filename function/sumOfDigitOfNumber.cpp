#include <iostream>
using namespace std;

int sumOfDigit(int number)
{
    int sum = 0;
    // sum += number % 10; 125 % 10 -> 5
    // number = number  10; 125 / 10 -> 12
    // sum += number % 10; 12 % 10 -> 2
    // number = number  10; 12 / 10 -> 1
    // sum += number; 1/10 -> 0 (number == 0 True it will terminate the program)
    while (number > 0)
    {
        sum += number % 10;
        number = number / 10;
    }

    return sum;
}

int main()
{
    cout << sumOfDigit(12222) << endl;
    return 0;
}
