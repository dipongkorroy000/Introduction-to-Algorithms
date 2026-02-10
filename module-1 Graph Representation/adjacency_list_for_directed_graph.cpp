#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n]; // array of vector

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        // adj_list[b].push_back(a); when undirected graph
    }

    for (int i = 0; i < e; i++)
    {
        cout << i << " -> ";
        for (int j : adj_list[i])
            cout << j << " ";

        cout << endl;
    }

    return 0;
}

/**
 * in ->                    node(0)
 * 5 5                     /   |   \
 * 0 1              node(1)    |     node(2)
 * 0 2                     \   |
 * 0 3                      node(3)----node(4)
 * 1 3
 * 3 4
 *
 * out ->
 * 0 -> 1 2 3 
 * 1 -> 3 
 * 2 -> 
 * 3 -> 4 
 * 4 -> 
 * 
 */