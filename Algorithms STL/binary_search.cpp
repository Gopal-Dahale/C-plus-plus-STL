#include <iostream>
#include <algorithm>
using namespace std;

// utility function to print the result

void result(auto start, auto end, auto res, int key)
{
    if (*res == key)
        cout << "Element found at index " << res - start << "\n";
    else if (res == end)
        cout << "Element not found; No greater element than " << key << " exists in the container\n";
    else
        cout << "Next greater element than " << key << " is " << *res << " at index " << res - start << "\n";
}

int main()
{
    //sorted array
    int a[] = {1, 2, 3, 4, 5, 6, 6, 6, 8, 8, 9};
    int n = sizeof(a) / sizeof(int);

    // returns true if the element is present in the container, else returns false
    if (binary_search(begin(a), end(a), 3))
        cout << "Element found\n";
    else
        cout << "Element not found\n";

    // to get the index of element in sorted array we can use the following functions
    /*
        lower_bound(start_ptr, end_ptr, num)

        * Returns pointer to “position of num” if container contains 1 occurrence of num.
        * Returns pointer to “first position of num” if container contains multiple occurrence of num. 
        * Returns pointer to “position of next higher number than num” if container does not contain occurrence of num.
    */
    int key;

    // key exists in array
    key = 3;
    auto res = lower_bound(begin(a), end(a), key);
    result(begin(a), end(a), res, key);

    // key does not exists in array but next greater element exists in array
    key = 7;
    auto res1 = lower_bound(begin(a), end(a), key);
    result(begin(a), end(a), res1, key);

    // neither key exists nor next greater element exists in array
    key = 10;
    auto res2 = lower_bound(begin(a), end(a), key);
    result(begin(a), end(a), res2, key);

    cout << " ----------------- \n";
    /*
        upper_bound(start_ptr, end_ptr, num)

        * Returns pointer to “position of next higher number than num” if container contains 1 occurrence of num. 
        * Returns pointer to “first position of next higher number than last occurrence of num” if container contains multiple occurrence of num. 
        * Returns pointer to “position of next higher number than num” if container does not contain occurrence of num.
    */

    // key exists in array
    key = 3;
    auto r = upper_bound(begin(a), end(a), key);
    result(begin(a), end(a), r, key);

    // key does not exists in array but next greater element exists in array
    key = 6;
    auto r1 = upper_bound(begin(a), end(a), key);
    result(begin(a), end(a), r1, key);

    // neither key exists nor next greater element exists in array
    key = 10;
    auto r2 = upper_bound(begin(a), end(a), key);
    result(begin(a), end(a), r2, key);

    cout << " ----------------- \n";

    // using lower_bound and upper_bound to find frequency of a key in a sorted array in O(logn) time
    for (int i = 0; i < n; i++)
    {
        // takes O(logn) for each key
        key = a[i];
        cout << "frequency of " << key << " is " << upper_bound(begin(a), end(a), key) - lower_bound(begin(a), end(a), key) << "\n";
    }

    return 0;
}
