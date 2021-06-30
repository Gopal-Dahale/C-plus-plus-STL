#include <iostream>
#include <queue>

using namespace std;

// function to print queue
void print(queue<int> &q)
{

    while (!q.empty()) // returns true if queue is empty
    {
        cout << q.front() << " ,"; //access the first element
        q.pop();                   //removes the first element
    }
    cout << "\n";
}

int main()
{
    // FIFO
    queue<int> q;

    // inserts element at the end
    for (int i = 0; i < 10; i++)
        q.push(i);

    // constructs element in-place at the end
    q.emplace(10);

    // access the first element
    cout << "front element is " << q.front() << "\n";

    // access the last element
    cout << "last element is " << q.back() << "\n";

    // size of queue
    cout << "the size of queue is " << q.size() << "\n";

    // printing queue
    print(q);

    // empty
    if (q.empty())
        cout << "queue is empty\n";
    return 0;
}
