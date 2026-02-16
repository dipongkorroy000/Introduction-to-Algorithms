#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
int vis_ary[101];

void dfs(int src)
{
    // cout << src << " ";
    vis_ary[src] = true;
    for (int child : adj_list[src])
    {
        if (vis_ary[child] == false)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis_ary, false, sizeof(vis_ary));

    int count =0;
    for (int i = 0; i < n; i++)
    {
        if (vis_ary[i] == false)
        {
            dfs(i);
            // cout << endl;
            count++;
        }
    }

    cout << "components = " << count << endl;

    return 0;
}

/**
 * in -> nodes, connection/edge
 * 8 6
 * 1 2          0           1           6
 * 2 3         /           / \          |
 * 1 3        5---4       2---3         7
 * 4 5
 * 5 0
 * 6 7
 * 
 * out ->
 * components = 3
 */