#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edge_list; // array of vector
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        edge_list.push_back({a, b});
    }
    // alternative ---
    // vector<pair<int, int>> edge_list(n); // array of vector
    // for (int i = 0; i < n; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;

    //     edge_list[i].first = a;
    //     edge_list[i].second = b;
    // }

    for (int i = 0; i < e; i++)
    {
        cout << edge_list[i].first << " " << edge_list[i].second << endl;
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
 * 0 1
 * 0 2
 * 0 3
 * 1 3
 * 3 4
 *
 */