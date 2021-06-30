#include <iostream>
#include <stack>

using namespace std;

// to iterate over stack we have to print the topmost element and then pop it
void print(stack<int> &s)
{
    while (!s.empty()) // stack is not empty
    {
        cout << s.top() << ", "; // prints the topmost element
        s.pop();                 // pops the topmost element from stack
    }
    cout << "\n";
}

int main()
{
    stack<int> s;

    // push
    for (int i = 0; i < 10; i++)
        s.push(i);

    // iterating over stack
    print(s);
    // now stack is empty
    if (s.empty())
        cout << "stack is empty\n";

    for (int i = 0; i < 10; i++)
        s.push(i);

    // size of stack
    cout << "stack contains " << s.size() << " elements\n";

    // emplace
    // constructs element in-place at top
    s.emplace(32);
    print(s);

    while (!s.empty()) // stack is not empty
    {                  // prints the topmost element
        s.pop();       // pops the topmost element from stack
    }
    cout << s.empty() << "\n";
    cout << s.top();
    return 0;
}
