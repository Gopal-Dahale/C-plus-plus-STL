#include <ext/pb_ds/assoc_container.hpp> // common file
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{

    pbds ds;

    ds.insert(10);
    ds.insert(1);
    ds.insert(15);
    ds.insert(4);
    ds.insert(3);

    for (auto &i : ds)
        cout << i << " ";
    cout << "\n";

    // find_by_order
    // returns iterator to kth largest element starting from zero
    // O(logn)

    for (int i = 0; i < ds.size(); i++)
        cout << i << " " << *ds.find_by_order(i) << "\n";

    // order_of_key
    // returns number of elements striclty smaller than given element
    // O(logn)
    cout<<"-------------\n";
    cout << ds.order_of_key(5) << "\n";
    cout << ds.order_of_key(11) << "\n";

    return 0;
}
