// linear search implementation with template programming

#include <iostream>

using namespace std;

// linear search template function

template <typename T>
int search(T a[], int n, T key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;

    return -1;
}

// utility function to display result
void result(int res)
{
    if (res != -1)
        cout << "Element found at index " << res << "\n";
    else
        cout << "Element not found\n";
}

int main()
{
    // array of integers
    int a[] = {5, 3, 6, 7, 2, 3, 4, 9, 1, 0};
    int n = sizeof(a) / sizeof(int);

    int res = search<int>(a, n, 8); // explicit type is optional
    result(res);

    // array of characters
    char arr[] = {'a', 'c', 'd', 'r', 'b', 'e', 'z', 'p'};
    n = sizeof(a) / sizeof(int);

    res = search<char>(arr, n, 'e');
    result(res);

    return 0;
}
