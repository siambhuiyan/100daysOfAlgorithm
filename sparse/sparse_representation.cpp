#include <iostream>
using namespace std;

struct Element
{
    /* data */
    int i; // row number of the element
    int j; // column number of the element
    int x; // non zero element of the matrix
};

struct Sparse
{
    int m; // number of row dim
    int n; // number of column dim
    int z; // non zero value total
    struct Element *e;
};

void Create(struct Sparse *s)
{
    cout << "Enter the row and columns (Matrix dimension) : " << endl;
    cin >> s->m >> s->n;
    cout << endl;
    cout << "Enter the number of non zero value: " << endl;
    cin >> s->z;
    s->e = new Element[s->z];
    for (int i = 0; i < s->z; i++)
    {
        cout << "Enter non zero value one by one: ";
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;

        // Convert to 0-based indexing
        s->e[i].i -= 1;
        s->e[i].j -= 1;
    }
}

void display(struct Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                cout << s.e[k].x << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    struct Sparse S;
    Create(&S);
    display(S);
    delete[] S.e;
    return 0;
}
