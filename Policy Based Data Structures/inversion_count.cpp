/*
    inversions are pairs in array at index i,j such that
    i < j and a[i] > a[j]
*/
#include <ext/pb_ds/assoc_container.hpp> // common file
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
    // considering distint elements

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    pbds ds;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count += ds.size() - ds.order_of_key(v[i]);
        ds.insert(v[i]);
    }

    cout << count;

    return 0;
}
