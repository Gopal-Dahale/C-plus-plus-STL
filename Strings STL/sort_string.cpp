#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const string &x, const string &y)
{
    // if both strings are of same length we return lexi small string
    if (x.size() == y.size())
        return x < y;

    // else we return string wtih larger length
    return x.size() > y.size();
}

int main()
{
    //cook your dish here

    string s[3]{
        "apple juice",
        "banana juice",
        "mango juice"};

    sort(s, s + 3, cmp);

    for (auto &i : s)
        cout << i << "\n";

    return 0;
}
