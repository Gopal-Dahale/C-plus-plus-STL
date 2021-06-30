#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // array of integers
    int v[]{-3, 5, 7, -8, 9, -2, 4, 6};
    int n = sizeof(v) / sizeof(int);

    // swap two numbers , can also work with container elements
    int a{10}, b{20};
    swap(a, b);

    cout << a << " " << b << "\n";

    // to find max and min of two numbers

    cout << max(a, b) << "\n";
    cout << min(a, b) << "\n";

    // to find max and min element in a range

    cout << *(max_element(v, v + n)) << "\n";
    cout << *(min_element(v, v + n)) << "\n";

    // to find max and min element in a range with comparator
    // lets say we have to find absolute max and min element

    cout << *(max_element(v, v + n, [](int x, int y) { return abs(x) < abs(y); })) << "\n";
    cout << *(min_element(v, v + n, [](int x, int y) { return abs(x) < abs(y); })) << "\n";

    // reversing array
    reverse(v, v + n);
    for_each(v, v + n, [](int x) { cout << x << " "; });

    return 0;
}
