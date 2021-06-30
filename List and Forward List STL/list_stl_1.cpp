// list in cpp stl is doubly linked list
// useful in case of insertion and deletion of data from the end
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
    list<int> l;

    // init
    list<string> s{"mango", "banana", "apple"};
    s.push_back("papaya");

    //iterate
    print(s);

    // sort
    s.sort();
    print(s);

    // reverse
    s.reverse();
    print(s);

    // front element and remove it
    cout << s.front() << "\n";
    s.pop_front();
    print(s);

    // add to front of list
    s.push_front("grapes");

    // last element and remove it
    cout << s.back() << "\n";
    s.pop_back();
    print(s);

    // iterating using iterator
    for (auto i = s.begin(); i != s.end(); i = next(i))
    {
        cout << *i << " -> ";
    }
    cout << "\n";

    return 0;
}
