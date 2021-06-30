#include <iostream>
#include <queue>

using namespace std;

// implementing queues using stack

template <typename T>
class Stack
{
private:
    queue<T> q1, q2;

public:
    // constant time
    void push(T data)
    {
        q1.push(data);
    }
    // order n time
    void pop()
    {
        // push first n-1 elements from q1 to q2
        // pop the last element from q1
        // swap q1 and q2
        if (q1.size() == 0)
            return;

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        // pops the last element from q1;
        q1.pop();

        // swaps q1 with q2
        q1.swap(q2);
    }

    // order n time
    T top()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        T top_element = q1.front();
        q2.push(q1.front());
        q1.pop();
        // swaps q1 with q2
        q1.swap(q2);

        return top_element;
    }

    int size()
    {
        return q1.size() + q2.size();
    }
    bool empty()
    {
        return (q1.size() == 0);
    }
};

// utility function to print stack
template <typename T>
void print(Stack<T> &s)
{
    while (!s.empty())
    {
        cout << s.top() << " ,";
        s.pop();
    }
    cout << "\n";
}

int main()
{

    Stack<int> s;

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

    print(s);
    return 0;
}
