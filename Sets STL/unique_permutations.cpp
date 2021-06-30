// generating permutations using recursion
// using set to store only unique permutations
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

void permutation(string x, int start, int end, set<string> &s)
{
    
    if (start == end)
    {
        s.insert(x);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(x[start],x[i]);
        permutation(x,start+1,end,s);
        swap(x[start],x[i]);
    }
}

int main()
{
    string x = "ACC";
    set<string> s;
    permutation(x, 0, x.size() - 1,s);
    for_each(s.begin(),s.end(),[&](string x){cout<< x<<'\n';});
    return 0;
}

/*
    Drawback
    1. generates duplicates if characters are repeated

*/