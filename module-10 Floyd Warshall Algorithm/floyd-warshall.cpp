#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj_mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        adj_mat[a][b] = w;
        // adj_mat[b][a] = w; // if undirected
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout << i << " " << k << " " << j << endl;
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_mat[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 * in -> directed graph
 * 4 5
 * 0 1 3
 * 0 2 6
 * 1 2 2
 * 1 3 5
 * 2 3 4
 * 
 * out ->
 * 0   3   5   8 
 * INF 0   2   5 
 * INF INF 0   4 
 * INF INF INF 0 
 * 
 * in -> undirected graph
 * 3 3
 * 0 2 3
 * 0 1 5
 * 2 1 1
 * 
 * out ->
 * 0 4 3 
 * 4 0 1 
 * 3 1 0 
 */