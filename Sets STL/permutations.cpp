// generating permutations using recursion
#include <iostream>
#include <string>
using namespace std;

void permutation(string x, int start, int end)
{
    static int count = 1;
    if (start == end)
    {
        cout << count << " ";
        ++count;
        cout << x << '\n';
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(x[start],x[i]);
        permutation(x,start+1,end);
        swap(x[start],x[i]);
    }
}

int main()
{
    string x = "ABC";
    permutation(x, 0, x.size() - 1);

    return 0;
}

/*
    Drawback
    1. generates duplicates if characters are repeated

*/