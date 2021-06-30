#include <iostream>
#include <queue>

// for generating random numbers
#include <ctime>
#include <cstdlib>
using namespace std;

// adds random numbers in the priority_queue
// variadic templates
template <typename... Types> 
void init(priority_queue<int, Types...> &pq, int n)
{
    int lower = 0, upper = 20;

    // use current time as seed for random generator
    srand(time(nullptr));

    for (int i = 0; i < n; i++)
        pq.push((rand() % (upper - lower + 1)) + lower); // inserts element and sorts the underlying container

    // complexity of each insertion is O(logn)
}

int main()
{
    // uses heap as its underlying data strucutre;
    priority_queue<int> pq; // max heap
    init(pq, 10);

    // removing elements from heap
    while (!pq.empty())
    {
        cout << pq.top() << ", "; // accesses the top element
        pq.pop();                 //removes the top element
    }
    cout << "\n";

    // min heap 
    priority_queue<int, vector<int> , greater<int> > pq2;

    init(pq2, 10);

    // removing elements from heap
    while (!pq2.empty())
    {
        cout << pq2.top() << ", "; // accesses the top element
        pq2.pop();                 //removes the top element
    }
    cout << "\n";
    return 0;
}
