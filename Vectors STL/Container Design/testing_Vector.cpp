#include <iostream>
#include "vector.h"
using namespace std;

void print(Vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    //cook your dish here
    Vector<int> v;

    for (int i = 0; i < 5; i++)
        v.push_back(i);
    print(v);

    cout << v.at(2) << '\n';

    v.pop_back();
    print(v);
    cout << v.front() << "\n";
    cout << v.back() << "\n";

    cout << v.size() << "\n";
    cout << v.capacity() << "\n";

    if (v.empty())
        cout << "vector is empty\n";
    else
        cout << "vector has some elements\n";

    return 0;
}
