#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // declaration and initialisation

    vector<int> a;
    vector<int> b(5, 10);              // vector of size 5 with all elements initialised to 10
    vector<int> c(b.begin(), b.end()); // init a vector by another vector
    vector<int> d{1, 2, 3, 4, 5};

    // iterate over the vector
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << "\n";

    for (auto i = d.begin(); i != d.end(); i = next(i))
        cout << *i << " ";
    cout << "\n";

    // for each loop
    for (int &i : b)
        cout << i << " ";
    cout << "\n";

    // taking input in vector
    int x, n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    /*
        consider two vectors 'd' (initialised at the time of declaration) and 'v' (elements added using loop)
        Understand differences in both at memory level
    */
    cout << v.size() << "\n";
    cout << v.capacity() << "\n"; // size of underlying arrray
    cout << v.max_size() << "\n"; //max no of elements vector can hold in worst case

    cout << d.size() << "\n";
    cout << d.capacity() << "\n"; // size of underlying arrray
    cout << d.max_size() << "\n"; //max no of elements vector can hold in worst case

    /*  
        v.capacity() is 8 because vector keeps doubling the size whenever we push back element
        In the beginning capacity is 1

        push number                 capacity
        
        after first push     ->      2
        after second push    ->      4
        after third push     ->      4
        after fourth push    ->      8
        after fifth push     ->      8

        doubling is an expensive operation. 
        We will try to find a new method to avoid doubling.
    */

   
    return 0;
}
