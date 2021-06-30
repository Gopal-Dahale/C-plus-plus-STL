#include <iostream>
#include <list>

using namespace std;

// utility function to print list
template <typename T>
void print(list<T> &s)
{
    for (auto &i : s)
        cout << i << " -> ";

    cout << "\n";
}

int main()
{
    // some more functions on list
    list<int> l{1, 1, 1, 2, 3, 4, 5, 6, 8};

    // remove particular element
    // removes all occurences of the element
    // removes nothing if the element is not present
    l.remove(1);
    print(l);

    //erase 1 or more elements from list
    // auto it = l.begin()+ 4; // this line will show error as list in not a contiguous data structure

    auto it = l.begin();
    it = next(next(it)); // takes you to the third element
    l.erase(it);
    print(l);

    // insert elements in lista
    auto i = l.end();
    i = prev(prev(i));
    l.insert(i, 7);
    print(l);
    return 0;
}
