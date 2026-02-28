#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj_list[n][n];

    memset(adj_list, 0, sizeof(adj_list));

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        adj_list[a][b] = w;
        adj_list[b][a] = w;
    }

    for (int i = 0; i < n; i++)
    {
        for (int pr : adj_list[i])
        {
            cout << pr << "  ";
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
 *     0  1  2 3 4
 * -----------------
 * 0 | 0  10 7 4 0 
 * 1 | 10 0  1 0 3 
 * 2 | 7  1  0 1 5 
 * 3 | 4  0  1 0 5 
 * 4 | 0  3  5 5 0 
 * 
 */