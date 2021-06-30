// implementing adjacency list for weighted graph
#include <iostream>
#include <list>

using namespace std;

int main()
{
    // number of vertices
    int n;
    cin >> n;

    // array of lists for graph data structure
    list<pair<int, int>> *g = new list<pair<int, int>>[n];

    //input first vertex , second vertex and weight of edge
    int x, y, weight;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> weight;
        g[x].push_back({y, weight});
    }

    // print the graph
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto &p : g[i])
        {
            cout << "(" << p.first << ", " << p.second << "),";
        }
        cout << "\n";
    }

    return 0;
}
