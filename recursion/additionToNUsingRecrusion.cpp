#include <iostream>
#include <chrono>
using namespace std;
using namespace std ::chrono;

// recursive solution
int addNNumber(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    return addNNumber(n - 1) + n;
}

// iteration solution
int addNumberIter(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

// direct formula solution

int addUsingFormula(int n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    int n = 10000;

    // measure time for recrusive version
    auto start_recursive = high_resolution_clock::now();
    int result_recursive = addNNumber(n);
    auto end_recursive = high_resolution_clock::now();
    auto duration_recursive = duration_cast<nanoseconds>(end_recursive - start_recursive);

    // recrusive call result
    cout << "Recursive call : " << endl;
    cout << "The Sum of N numbers are : " << result_recursive << endl;
    cout << "Duration : " << duration_recursive.count() << " ns\n"
         << endl;

    // iteration call
    cout << "Iteration Call" << endl;
    cout << addNumberIter(n) << endl;

    // direct formula
    cout << "Direct formula call" << endl;
    cout << addUsingFormula(n);

    return 0;
}