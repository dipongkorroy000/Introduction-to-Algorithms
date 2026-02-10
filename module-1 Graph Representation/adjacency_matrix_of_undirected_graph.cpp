#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    int adj_mat[nodes][edges];

    // for (int i = 0; i < nodes; i++)
    //     for (int j = 0; j < edges; j++)
    //         adj_mat[i][j] = 0;
    // alternative--
    memset(adj_mat, 0, sizeof(adj_mat)); // all value = 0

    for(int i = 0; i< nodes; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;  // when undirected graph

        adj_mat[i][i] = 1;
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < edges; j++)
            cout << adj_mat[i][j] << " ";

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
 * 1 1 1 1 0 
 * 1 1 0 1 0 
 * 1 0 1 0 0 
 * 1 1 0 1 1 
 * 0 0 0 1 1 
 */