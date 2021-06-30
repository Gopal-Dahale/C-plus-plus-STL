#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm> // for_each
using namespace std;

// overloading cout for printing vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for_each(v.begin(), v.end(), [&](T x) { cout << x << " "; });
    return os;
}

// function to output data of given name if it exists
template <typename... Types>
void check(string name, unordered_map<Types...> &m)
{
    if (!m.count(name))
        cout << name << " not found\n";
    else
        cout << name << " " << m.at(name) << "\n";
}
int main()
{
    unordered_map<string, vector<string>> m;

    // person name with list of phone numbers
    m.insert({"Gopal", {"9110", "9111", "9112", "9113"}});
    m.insert({"Kajal", {"8110", "8111"}});
    m.insert({"Rahul", {"7110", "7111", "7114"}});

    // iterating over map
    for_each(m.begin(), m.end(), [&](auto p) { cout << p.first << " -> " << p.second << "\n"; });

    check("Shubham", m);
    check("Kajal", m);
    return 0;
}
