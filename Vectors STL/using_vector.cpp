// given (x,y) coordinates print their distances from origin in sorted order
// if distance of two points from origin is same then sort accoding to x coordinate

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    int d1 = pow(a.first, 2) + pow(a.second, 2);
    int d2 = pow(b.first, 2) + pow(b.second, 2);

    // distances are same
    if (d1 == d2)
        return a.first < b.first;

    return d1 < d2;
}

int main()
{
    //cook your dish here
    int n, x, y;
    cin >> n;

    vector<pair<int, int>> v;
    v.reserve(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.emplace_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), cmp);

    for_each(v.begin(), v.end(), [](pair<int,int> &x) { cout << x.first<< ", " <<x.second<<'\n'; });
    return 0;
}
