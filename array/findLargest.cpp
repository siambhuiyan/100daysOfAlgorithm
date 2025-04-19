#include <iostream>
#include <climits>
using namespace std;

int largestNum(int arr[6])
{
    int large = arr[0];
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] >= large)
            large = arr[i];
    }
    return large;
}

int findSmall(int arr[6])
{
    int small = arr[0];

    for (int i = 0; i < 6; i++)
    {
        if (arr[i] <= small)
            small = arr[i];
    }
    return small;
}

int findIndex(int arr[6], char sl)
{
    int indexS = -1;
    int indexL = -1;
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < 6; i++)
    {
        int indexS = smallest;
        int indexL = largest;
        smallest = min(arr[i], smallest);
        if (smallest < indexS)
            indexS = i;

        if (largest > indexL)
            indexL = i;
    }

    // what to return
    if (sl == 'L' || sl == 'l')
    {
        return indexL;
    }
    else
    {
        return indexS;
    }
}

int main()
{
    int arr[] = {
        5,
        15,
        22,
        1,
        -15,
        24,
    };

    int large = largestNum(arr);
    int small = findSmall(arr);
    int indexL = findIndex(arr, 'l');
    int indexS = findIndex(arr, 's');
    cout << "The largest number is : " << large << endl;
    cout << "The smallest number is : " << small << endl;

    // index finder
    cout << "The largest numbers index is : " << indexL << endl;
    cout << "The Smallest numbers index is : " << indexS << endl;

    return 0;
}
