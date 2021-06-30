// find the largest k elements in running stream
#include <iostream>
#include <queue>

using namespace std;

void print(priority_queue<int, vector<int>, greater<int>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

int main()
{
    int x{0};
    int c{0};
    int k;
    cin >> k;
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    while (1)
    {
        cin >> x;
        if (x == -1)
            break;
        else if (c < k)
        {
            pq.push(x);
            c++;
        }
        else if (c == k)
        {
            if (pq.top() < x)
            {
                pq.pop();
                pq.emplace(x);
            }
        }
    }
    print(pq);

    return 0;
}
