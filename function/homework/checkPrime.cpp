// Write a function to check if a number is prime or not

#include <iostream>
using namespace std;

bool isPrime(int num)
{
    // if number is <= 1 then return fasle (not a prime)
    if (num <= 1)
        return false;
    // check if it is between 2 and 3 then it is prime return true (prime)
    if (num <= 3)
        return true;

    // check whether it is divided by the 2 and 3
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    // sqrt(num) one of the factor of num must be less than or equal to this
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int num;
    cout << "Enter a number to check whether a number is prime or not: ";
    cin >> num;
    cout << "isPrim: " << isPrime(num) << endl;
    return 0;
}
