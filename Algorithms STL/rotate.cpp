// rotating array inplace using stl rotate
#include <iostream>
#include <algorithm>
using namespace std;

/*
    void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last):

    It rotates the order of the elements in the range [first,last], in such a way that the element pointed by middle becomes the new first element.
*/

// function to initialise array from 1 to n
void init(int a[], int n)
{
    static int temp = 1;
    for_each(a, a + n, [](int &x) { x = temp;  ++temp; });
    temp = 1;
}
// utilty function to print array
void print(int a[], int n)
{
    for_each(a, a + n, [](int &x) { cout << x << " "; });
    cout << "\n\n";
}
int main()
{
    //cook your dish here
    int a[8];
    int n = 8, k;

    // when k is less than n

    init(a, n);
    k = 3;
    cout << "Left rotation by " << k << "\n";
    rotate(a, a + k, a + n);
    print(a, n);

    init(a, n);
    k = 3;
    cout << "Right rotation by " << k << "\n";
    rotate(a, a + (n - k), a + n);
    print(a, n);

    // when k is greater than n
    // this is also valid for k less than n as modulo takes cares of it

    init(a, n);
    k = 15;
    cout << "Left rotation by " << k << "\n";
    rotate(a, a + (k % n), a + n);
    print(a, n);

    init(a, n);
    k = 15;
    cout << "Right rotation by " << k << "\n";
    rotate(a, a + (n - (k % n)), a + n);
    print(a, n);

    return 0;
}
