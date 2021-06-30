// linear search implementation with template programming, forward iterator

#include <iostream>
#include <iterator>
using namespace std;

// forward iterator example
// this depicts how stl search would have been implemented
template <typename ForwardIterator, typename T>
ForwardIterator mySearch(ForwardIterator start, ForwardIterator end, T key)
{
    while (start != end)
    {
        if (*start == key)
            return start;
        ++start;
    }
    return end;
}

int main()
{
    // array of integers
    int a[] = {5, 3, 6, 7, 2, 3, 4, 9, 1, 0};
    int n = sizeof(a) / sizeof(int);

    auto res = mySearch(begin(a), end(a), 6);
    if (res == end(a))
        cout << "Element not found\n";
    else
        cout << "Element found at index " << res - a << "\n";

    // array of characters
    char arr[] = {'a', 'c', 'd', 'r', 'b', 'e', 'z', 'p'};
    n = sizeof(a) / sizeof(int);

    auto res1 = mySearch(begin(arr), end(arr), 'z');
    if (res1 == end(arr))
        cout << "Element not found\n";
    else
        cout << "Element found at index " << res1 - arr << '\n';
    return 0;
}
