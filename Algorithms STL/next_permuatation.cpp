#include <iostream>
#include <algorithm>

using namespace std;

// utilty function to print array
void print(int a[], int n)
{
    for_each(a, a + n, [](int &x) { cout << x << " "; });
    cout << "\n";
}

int main()
{
    int a[]{1, 2, 3};
    int n = sizeof(a) / sizeof(int);

    // rearrange the elements in the range [first, last) into the next lexicographically greater permutation.
    next_permutation(a, a + n);
    print(a, n);

    next_permutation(a, a + n);
    print(a, n);

    next_permutation(a, a + n);
    print(a, n);

    next_permutation(a, a + n);
    print(a, n);

    cout << " ----------------- \n";

    //rearranges the elements in the range [first, last) into the previous lexicographically-ordered permutation.
    prev_permutation(a, a + n);
    print(a, n);

    prev_permutation(a, a + n);
    print(a, n);

    prev_permutation(a, a + n);
    print(a, n);

    prev_permutation(a, a + n);
    print(a, n);

    return 0;
}
