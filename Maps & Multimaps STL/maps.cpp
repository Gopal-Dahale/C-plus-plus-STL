// key - value pair
// uses red black tree for implementation
// keys are ordered
#include <iostream>
#include <map>
#include <string>
#include <algorithm> // for_each
using namespace std;

// utility function to print map
template <typename T, typename U>
void print(map<T, U> &m)
{
    for_each(m.begin(), m.end(), [&](pair<T, U> p) { cout << p.first << " -> " << p.second << "\n"; });
}

int main()
{
    // declaration
    map<string, int> m0;

    // declaration and initialisation
    map<string, int> m1{
        {"one", 1},
        {"two", 2},
    };

    // insertion in map

    map<string, int> m;

    m.insert(make_pair("apple", 25)); // inserts elements or nodes
    m.insert({"mango", 30});
    m["banana"] = 27; // operator overloading

    //search

    string fruit = "mango";
    auto it = m.find(fruit); // finds element with specific key
    if (it == m.end())       // 	returns an iterator to the end => given fruit does not exist
        cout << "No fruit found\n";
    else
        cout << "price of " << it->first << " is " << it->second << "\n";

    // another way to find a particular key
    // stores only unique keys

    if (m.count(fruit)) // returns the number of elements matching specific key
        cout << "price of " << fruit << " is " << m[fruit] << "\n";
    else
        cout << "No fruit found\n";

    // erase
    m.erase(fruit); //erases elements

    // iterating over all key-value pairs
    for (auto it = m.begin(); it != m.end(); it = next(it))
        cout << it->first << " -> " << it->second << "\n";
    cout << "\n";
    // insert_or_assign

    //inserts an element or assigns to the current element if the key already exists
    m.insert_or_assign("apple", 40);
    m.insert_or_assign("grapes", 32);

    // printing the map
    print(m);

    // size of map
    cout << "size of map is " << m.size() << "\n"; //returns the number of elements

    cout << "max size of map is " << m.max_size() << "\n"; // returns the maximum possible number of elements

    m.emplace(make_pair("cherry", 13)); // constructs element in-place

    print(m);

    // clears the map
    m.clear();
    if (!m.size())
        cout << "map is empty\n";

    return 0;
}
