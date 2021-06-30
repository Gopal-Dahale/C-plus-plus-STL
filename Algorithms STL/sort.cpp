// sorting with stl sort
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct stud
{
    string name;
    int roll;
};

// comparing function for sorting structs wrt name in ascending order
bool cmp_name_ascend(stud a, stud b)
{
    return a.name < b.name;
}
bool cmp_name_descend(stud a, stud b)
{
    return a.name > b.name;
}
bool cmp_roll_ascend(stud a, stud b)
{
    return a.roll < b.roll;
}
bool cmp_roll_descend(stud a, stud b)
{
    return a.roll > b.roll;
}

// utility function to print objects of stud
void print(stud s[], int n)
{
    for (int i = 0; i < n; i++)
        cout << s[i].name << " -> " << s[i].roll << " \n";
}
int main()
{
    int a[] = {1, 4, 6, 2, 3, 8, 6, 4, 3, 9, 0, 2, 2, 5};
    int n = sizeof(a) / sizeof(n);

    // sort from <algorithm>
    // default sorting order is ascending
    sort(a, a + n);

    for (auto &i : a)
        cout << a[i] << " ";
    cout << "\n";

    // descending sort
    sort(a, a + n, greater<int>());

    for (auto &i : a)
        cout << a[i] << " ";
    cout << "\n";

    // sorting array of structs
    stud s[] = {
        {"Gopal", 24},
        {"Shubham", 2},
        {"Raj", 31},
        {"Chinmay", 7},
        {"Siddharth", 5},
        {"Krishn", 16},
        {"Punit", 19},
    };

    n = sizeof(s) / sizeof(stud);

    // passing function by name for sorting wrt names
    sort(s, s + n, cmp_name_ascend);
    print(s, n);

    cout << " ----------------- \n";
    sort(s, s + n, cmp_name_descend);
    print(s, n);

    cout << " ----------------- \n";
    sort(s, s + n, cmp_roll_ascend);
    print(s, n);

    cout << " ----------------- \n";
    sort(s, s + n, cmp_roll_descend);
    print(s, n);

    return 0;
}
