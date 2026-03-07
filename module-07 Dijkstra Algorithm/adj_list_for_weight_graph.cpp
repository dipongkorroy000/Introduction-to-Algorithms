#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> adj_list[n];

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " to ->";
        // for (pair<int, int> pr : adj_list[i])
        // {
        //     cout << pr.first << " " << pr.second << ", ";
        // }
        // alternative auto keyword
        for (auto pr : adj_list[i])
        {
            cout << pr.first << " dis :" << pr.second << ", ";
        }
        cout << endl;
    }

    return 0;
}

/**
 * in ->                    10
 * 5 8                 0---------1
 * 0 1 10              | \     / |
 * 0 2 7               | 7\   /1 |
 * 0 3 4               |   \ /   |
 * 1 4 3              4|    2    |3
 * 1 2 1               |   / \   |
 * 2 4 5               | 1/   \5 |
 * 2 3 1               | /     \ | 
 * 3 4 5               3---------4
 *                          5
 * 
 * out ->
 * 0 to ->1 dis :10, 2 dis :7, 3 dis :4, 
 * 1 to ->0 dis :10, 4 dis :3, 2 dis :1, 
 * 2 to ->0 dis :7, 1 dis:1, 4 dis :5, 3 dis :1, 
 * 3 to ->0 dis :4, 2 dis:1, 4 dis :5, 
 * 4 to ->1 dis :3, 2 dis:5, 3 dis :5, 
 * 
 */