// pre requiste : function pointer
#include <vector>
#include <iostream>
using namespace std;

void iterate(vector<int> &v, void (*multiplyBy2)(int &))
{
    // instead of defining a function pointer we use lambda (anonymous function)
    for (auto &value : v)
        multiplyBy2(value);
}

int main()
{
    vector<int> v{1, 4, 5, 3, 5, 9};

    auto lambda = [](int &value) { value = value * 2; };
    // we pass a lambda
    iterate(v, lambda);

    for (auto &i : v)
        cout << i << " ";
    return 0;
}
