// stores unique elements only
// stores data in sorted order
// underlying data structure => self balancing Bst , red black tree
// cannot update elements once stored in set.
// to update elements pop it and push updated value in set

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// overloading cout to print a pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p)
{
    os << "{ " << p.first << "," << p.second << " }";
    return os;
}

// utitlity function to print set
template <typename T>
void print(set<T> s)
{
    for_each(s.begin(), s.end(), [&](T x) { cout << x << " "; });
    cout << "\n";
}

int main()
{
    int a[] = {8, 3, 2, 4, 5, 9, 0, 3, 2, 8, 7};
    int n = sizeof(a) / sizeof(int);

    set<int> s; // declaration

    for_each(begin(a), end(a), [&](int x) { s.insert(x); }); // inserts elements or nodes

    // printing set
    for (auto &i : s)
        cout << i << " ";
    cout << "\n";

    // erases elements
    s.erase(9);
    s.erase(10); // since 10 is not present nothing will happen

    // erasing using iterator
    auto it = s.find(2);
    s.erase(it);

    print(s);

    // set of pairs
    set<pair<int, string>> sp;
    sp.emplace(make_pair(0, "a"));
    sp.emplace(make_pair(1, "b"));
    sp.emplace(make_pair(2, "c"));
    sp.emplace(make_pair(3, "c"));
    sp.emplace(make_pair(1, "b"));
    sp.emplace(make_pair(0, "k"));
    sp.emplace(make_pair(2, "d"));
    sp.emplace(make_pair(1, "e"));

    print(sp);

    // erase pair
    sp.erase({0,"a"});

    print(sp);
    
    return 0;
}
