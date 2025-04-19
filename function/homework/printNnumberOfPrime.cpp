#include <iostream>
using namespace std;

// check prime or not
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
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

// print the n number of prime
void printPrime(int number)
{
    for (int i = 1; i <= number; i++)
    {
        bool isP = isPrime(i);
        if (isP)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Enter input here to check all the avaiable prime: ";
    cin >> n;
    printPrime(n);
    return 0;
}
