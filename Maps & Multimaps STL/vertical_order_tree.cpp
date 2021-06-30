// print binary tree in vertical order
/*

        1
       / \
      2  3
    / \  / \ 
   4  5 6  7
      \    \
      8    9

output :
4
2 
1 5 6
3 8
7
9

we can use map with given key value pair

-2  ->  4
-1  ->  2
0   ->  1 5 6
1   ->  3 8
2   ->  7
3   ->  9


*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // for_each
using namespace std;

// we will traverse the tree and use a variable for distance and then insert them in map

// class node
template <typename T>
class node
{
public:
    T data;
    node<T> *left, *right;
    node(T data) : data{data}, left{nullptr}, right{nullptr} {}
};

// traversl
template <typename T>
void traversal(node<T> *root, int d, map<T, vector<T>> &m)
{
    // base case
    if (root == NULL)
        return;
    m[d].emplace_back(root->data);
    traversal(root->left, d - 1, m);
    traversal(root->right, d + 1, m);
}

// cout is overloade for printing vector
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) 
{
    cout << "[ ";
    for_each(v.begin(), v.end(), [&](T x) { os << x << " "; });
    cout << "]";
    return os;
}

// utility function to print map
template <typename T, typename U>
void printMap(map<T, U> &m)
{
    for_each(m.begin(), m.end(), [&](pair<T, U> p) { cout << p.first << " -> " << p.second << "\n"; });
}
int main()
{
    // binary tree creation
    node<int> *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(8);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(9);

    map<int, vector<int>> m;

    // traversing the tree and updating the map
    // second parameter is used for disatance d
    traversal(root, 0, m);
    printMap(m);
    return 0;
}
