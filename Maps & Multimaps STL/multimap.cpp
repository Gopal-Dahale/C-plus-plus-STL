// multiple entries with the same key are allowed
#include <iostream>
#include <map>
#include <string>
using namespace std;


// utitlity function to print multimap
template <typename T, typename U>
void print(multimap<T, U> &m)
{
    for_each(m.begin(), m.end(), [&](pair<T, U> p) { cout << p.first << " -> " << p.second << "\n"; });
}

int main()
{
    multimap<char, string> m{
        {'b', "boat"},
        {'c', "car"},
        {'b', "batman"},
        {'c', "cat"},
        {'d', "dog"},
        {'e', "eye"},
        {'e', "energy"},
    };
    print(m);

    
    m.insert(make_pair('f', "fresh")); // inserts elements or nodes
    m.insert({'g', "grapes"});
    // m['g'] = "garage"; // operator overloading will not work
    
    //search

    char ch = 'b';
    auto it = m.find(ch); // finds element with specific key
    if (it == m.end())       // 	returns an iterator to the end => given fruit does not exist
        cout << "Not found\n";
    else
        cout << "value of " << it->first << " is " << it->second << "\n";

    // another way to find a parti cular key
    // stores only unique keys

    cout<< "count of "<<ch<<" is "<<m.count(ch)<<"\n"; // returns the number of elements matching specific key

    // erase
    m.erase(ch); //erases elements

    // iterating over all key-value pairs
    for (auto it = m.begin(); it != m.end(); it = next(it))
        cout << it->first << " -> " << it->second << "\n";
    cout << "\n";

    // printing the map
    print(m);

    // size of map
    cout << "size of map is " << m.size() << "\n"; //returns the number of elements

    cout << "max size of map is " << m.max_size() << "\n"; // returns the maximum possible number of elements

    m.emplace(make_pair('c', "cherry")); // constructs element in-place

    print(m);

    // clears the map
    m.clear();
    if (!m.size())
        cout << "map is empty\n";

    return 0;
}
