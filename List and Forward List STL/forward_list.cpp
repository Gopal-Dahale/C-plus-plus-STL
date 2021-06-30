// forward list is a singly linked list
// drawback is direct access to element is not possible
#include <iostream>
#include <forward_list>

using namespace std;

// utility function to print forward list
template <typename T>
void print(forward_list<T> &s)
{
    for (auto &i : s)
        cout << i << " -> ";

    cout << "\n";
}

int main()
{

    forward_list<int> l{2, 3, 4, 5, 1, 1, 6, 7, 8};

    // basic methods with forward list

    // no push_back method
    l.push_front(0);
    print(l);

    l.pop_front();
    print(l);

    l.sort();
    print(l);

    l.reverse();
    print(l);

    // remove method // removes all occurences of element
    l.remove(1);
    print(l);

    // erase_after method
    // removes element next to specified iterator
    auto it = l.begin();
    it = next(next(it)); // takes you to the third element
    l.erase_after(it);
    print(l);

    // merging two sorted lists
    // useful for merge sort

    forward_list<int> l1{6, 5, 2};
    forward_list<int> l2{9, 3, 1};

    l1.sort();
    l2.sort();

    l1.merge(l2);
    print(l1);

    return 0;
}
