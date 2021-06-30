#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Queue
{
private:
    stack <T> s1,s2;
public:
    void push(T data){
        s1.push(data);
    }
    void pop(){
        if(s1.empty() && s2.empty()){
            return;
        }

        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int size(){
        return s1.size() + s2.size();
    }
    T front(){

        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    T back(){
        if(!s1.empty())
            return s1.top();
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return s1.top();
    }
    bool empty(){
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};

// function to print queue
void print(Queue<int> &q)
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
    Queue<int> q;

    // inserts element at the end
    for (int i = 0; i < 10; i++)
        q.push(i);

    // access the first element
    cout << "front element is " << q.front() << "\n";

    // access the last element
    cout << "last element is " << q.back() << "\n";

    // size of queue
    cout << "the size of queue is " << q.size() << "\n";

    q.pop();
    q.pop();

    // empty
    if (q.empty())
        cout << "queue is empty\n";
    
    
    
    return 0;
}
