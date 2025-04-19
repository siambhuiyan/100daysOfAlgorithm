#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int bredth;
} r1 = {12, 100};

int main()
{
    struct Rectangle r;
    r.length = 10;
    cout << r1.length;
    // array of struct
    struct Rectangle s[10];
    return 0;
}
