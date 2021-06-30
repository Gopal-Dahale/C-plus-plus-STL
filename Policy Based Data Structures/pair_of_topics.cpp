// https://codeforces.com/problemset/problem/1324/D

#include <ext/pb_ds/assoc_container.hpp> // common file
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        c[i] = a[i] - b[i];

    pbds ds;
    long long int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += ds.size() - ds.order_of_key({-c[i], INT32_MAX});
        ds.insert({c[i], i});
    }
    cout << count;
    return 0;
}
