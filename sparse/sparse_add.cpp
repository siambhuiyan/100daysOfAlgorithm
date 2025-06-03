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

Sparse *add(struct Sparse *s, struct Sparse *s1)
{
    if (s->m != s1->m || s->n != s1->n)
        return nullptr;

    Sparse *sum = new Sparse;
    sum->m = s->m;
    sum->n = s->n;
    sum->e = new Element[s->z + s1->z]; // maximum size
    int i = 0, j = 0, k = 0;

    // Merge both sparse matrices in row-major order
    while (i < s->z && j < s1->z)
    {
        if (s->e[i].i < s1->e[j].i ||
            (s->e[i].i == s1->e[j].i && s->e[i].j < s1->e[j].j))
        {
            sum->e[k++] = s->e[i++];
        }
        else if (s->e[i].i > s1->e[j].i ||
                 (s->e[i].i == s1->e[j].i && s->e[i].j > s1->e[j].j))
        {
            sum->e[k++] = s1->e[j++];
        }
        else
        {
            // Same position → add values
            int val = s->e[i].x + s1->e[j].x;
            if (val != 0)
            {
                sum->e[k] = s->e[i];
                sum->e[k++].x = val;
            }
            i++;
            j++;
        }
    }

    // Copy remaining elements
    while (i < s->z)
        sum->e[k++] = s->e[i++];
    while (j < s1->z)
        sum->e[k++] = s1->e[j++];

    sum->z = k; // actual non-zero count
    return sum;
}

int main()
{
    struct Sparse S, S1;
    Create(&S);
    Create(&S1);
    display(S);
    display(S1);

    Sparse *sum = add(&S, &S1);
    Sparse s3 = *sum;
    display(s3);
    return 0;
}
