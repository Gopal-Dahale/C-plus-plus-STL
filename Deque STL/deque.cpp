// doubly ended queue
// individual elements can be accessed directly
// for operations involving exapansions or contractions in the end, deque is best
// for operations involving frequent insertions or removal of positions in between, deque performs worse

#include <iostream>
#include <deque>
#include <algorithm> // for for_each
using namespace std;

// function to init deque
void init(deque<int> &q)
{
    for (int i = 0; i < 10; i++)
        q.push_back(i); // adds an element to the end
}

void print(deque<int> &q)
{
    // iteration
    for_each(q.begin(), q.end(), [](int &x) { cout << x << " -> "; });
    cout << "\n";
}

int main()
{
    deque<int> q;

    init(q);
    print(q);

    q.push_back(10);  // adds an element to the end
    q.push_front(-1); // inserts an element to the beginning

    print(q);

    q.pop_back();  // removes the last element
    q.pop_front(); // removes the first element

    print(q);

    q.emplace_back(10);  // constructs an element in-place at the end
    q.emplace_front(10); // constructs an element in-place at the beginning

    print(q);

    // insert
    // costly operation for deque
    q.insert(q.begin() + 3, 12); // inserts element at 4th position
    print(q);

    cout << "front element is " << q.front() << "\n";
    cout << "last element is " << q.back() << "\n";

    // iterating deque is operator[]
    for (int i = 0; i < q.size(); i++)
        cout << q[i] << " ,";
    cout << "\n";

    //erase
    // costly operation for deque
    q.erase(q.begin(), q.begin() + 3); //erases first three elements
    print(q);
    return 0;
}
