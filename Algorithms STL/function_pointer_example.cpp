// we create a function to iterate over a vector and perform some action over its elements (multiply by 2) by using other function which is passed to the iterating function

#include <iostream>
#include <vector>

using namespace std;

void mul2(int &value)
{
    value = value * 2;
}

void iterate(vector<int> &v, void (*multiplyBy2)(int &))
{
    for (auto &value : v)
    {
        // perfom the action here
        multiplyBy2(value);
    }
}

int main()
{
    vector<int> v{1, 4, 5, 3, 5, 9};

    //tell this function the action we want to perform by giving it a function as a parameter
    iterate(v, mul2);

    for (auto &i : v)
        cout << i << " ";
    return 0;
}
