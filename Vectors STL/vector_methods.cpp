#include <iostream>
#include <vector>
#include <algorithm> // for_each() method
using namespace std;

// utility method to print vector
void print(vector<int> &v)
{
    for_each(v.begin(), v.end(), [](int &x) { cout << x << " "; });
    cout << "\n";
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // push_back to v
    v.push_back(6);
    print(v);

    // pop from back
    v.pop_back();
    print(v);

    // insert element in vector
    v.insert(v.begin() + 3, 100); // inserts 100 starting at position 3
    print(v);

    // insert more than 1 element in vector
    v.insert(v.begin() + 3, 4, 200); // inserts 4 200's starting from position 3
    print(v);

    //erase element
    v.erase(v.begin() + 2); // erases the element at index 2
    print(v);

    // erases multiple elements from vector
    v.erase(v.begin() + 2, v.begin() + 5); // erases elements at indices 2,3,4
    print(v);

    // size of vector
    cout << v.size() << "\n";

    // capacity of vector // size of underlying array
    cout << v.capacity() << "\n";

    //resizing vector
    cout << "after resizing vector\n";
    v.resize(v.size() + 2);
    cout << "size: " << v.size() << "\n";           // size changes
    cout << "capacity: " << v.capacity() << "\n\n"; // capacity is not affected since the new size is still  less than capacity

    cout << "after resizing of vector more than its current capacity\n";
    v.resize(v.capacity() + 10);
    cout << "size: " << v.size() << "\n";
    cout << "capacity: " << v.capacity() << "\n\n"; // now capacity is equal to new size of vector

    // shrinking vector
    // we usually avoid shrink
    cout << "shrinking vector\n";
    v.resize(4);
    print(v);
    cout << "size: " << v.size() << "\n";           // changes to new size
    cout << "capacity: " << v.capacity() << "\n\n"; // capacity does not change

    // clear a vector
    // removes all the elements, doesn't delete the memory occupied by vector
    v.clear();
    print(v);                                       // empty vector
    cout << "size: " << v.size() << "\n";           // changes to 0
    cout << "capacity: " << v.capacity() << "\n\n"; // capacity does not change

    // check whether vector is empty
    if (v.empty())
        cout << "Vector is empty\n";

    // pushing some elements in vectors to demonstrate further operations
    for (int i = 0; i < 4; i++)
        v.push_back(i);

    // first element of vector
    cout << v.front() << "\n";

    //last element of vector
    cout << v.back() << "\n";

    // Reserve
    // cures doubling problem
    vector<int> a;
    a.reserve(100); // reserves 100 for 'a' , capacity will be 100 and will not change until pushing elements exceed 100
    cout << "capacity: " << a.capacity() << "\n";

    for (int i = 0; i < 10; i++)
        a.emplace_back(i); // directly adds the object to vector instead of creating the object and then adding to vector

    cout << "size: " << a.size() << "\n";
    cout << "capacity: " << a.capacity() << "\n\n"; // capacity does not change until we exceed it

    return 0;
}
