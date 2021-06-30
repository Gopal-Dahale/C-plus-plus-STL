#include <iostream>
#include <utility>

using namespace std;
int main()
{
    //cook your dish here
    pair<int, char> p;

    p.first = 1;
    p.second = 'a';
    cout << p.first << " -> " << p.second << "\n";

    // initialising pair

    // initialized
    pair<int, char> p2(2, 'b');
    cout << p2.first << " -> " << p2.second << "\n";

    //copy of p
    pair<int, char> p3(p);
    cout << p3.first << " -> " << p3.second << "\n";

    // using make_pair function
    pair<int, char> p4 = make_pair(4, 'x');
    cout << p4.first << " -> " << p4.second << "\n";

    cout << " ----------------- \n";
    // swap function for par

    p.swap(p2);
    cout << p.first << " -> " << p.second << "\n";
    cout << p2.first << " -> " << p2.second << "\n";
    return 0;
}
