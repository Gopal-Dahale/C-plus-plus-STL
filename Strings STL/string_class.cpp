#include <iostream>
#include <string>

using namespace std;

int main()
{
    // string init
    string s0;
    string s1("string1");
    string s2{"string2"};
    string s3 = "string3";
    string s4(s1);
    string s5 = s1;

    char a[] = {'a', 'b', 'c', 'd', '\0'};
    string s6{a};

    cout << s1 << "\n";
    cout << s2 << "\n";
    cout << s3 << "\n";
    cout << s4 << "\n";
    cout << s5 << "\n";
    cout << s6 << "\n";

    // check for empty string
    if (s0.empty()) // returns true if string is empty
        cout << "string is empty\n";

    // append
    s0.append("I love C++");
    cout << s0 << "\n";

    //  or use + operator
    s0 += " and python\n";
    cout << s0;

    // size of string
    cout << s0.size() << '\n';

    // clear the string
    s0.clear();
    cout << s0.size() << "\n";

    // compare two strings
    // returns 0 if strings are same
    // returns negative number if s0 is lexi smaller than s1
    // returns positive number if s0 is lexi larger than s1

    s0 = "Apple";
    s1 = "Mango";

    cout << s0.compare(s1) << "\n"; // comparing s0 with s1
    cout << s0.compare(s0) << "\n"; // comparing s0 with itself
    cout << s1.compare(s0) << "\n"; // comparing s1 with s0

    // comparison can also be done by overloading operators
    if (s0 < s1)
        cout << "Apple is lexi small than Mango\n";

    // finding substrings
    string s = "I want to have apple juice\n";
    int index = s.find("apple");
    cout << "apple is at index " << index << "\n";

    // erase (starting index, length of string to be removed)
    string word{"apple"};
    s.erase(index, word.size());
    cout << s;

    // iterating over strings
    for (int i = 0; i < s0.size(); i++)
        cout << s0[i] << " ";

    cout << "\n";
    for (auto &i : s)
        cout << i;

    // using iterators to iterate over string
    for (auto i = s0.begin(); i != s0.end(); i = next(i))
        cout << *i;
    cout << "\n";
    return 0;
}
