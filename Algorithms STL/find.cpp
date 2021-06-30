// using the find function to find an element in an unsorted array

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //cook your dish here
    int a[] = {1, 2, 3, 6, 5, 8, 9, 3, 4};
    int n = sizeof(a) / sizeof(n);

    // find returns and iterator pointed to the element of array if it is present otherwise returns end of array
    auto res = find(begin(a), end(a), 9);
    if (res == end(a))
        cout << "Element not found\n";
    else
        cout << "Element found at index " << res - begin(a) << "\n";

    return 0;
}
