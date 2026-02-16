#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool vis_ary[101];

void dfs(int src)
{
    // base case
    cout << src << " ";
    vis_ary[src] = true;

    for (int child : adj_list[src])
        if (!vis_ary[child]) dfs(child);

    return;
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

    dfs(0); // source = 0

    return 0;
}

/**
 * in ->
 * 7 7                  0
 * 0 2                / | \
 * 2 4               /  |  \
 * 0 1              1---3   2
 * 1 5              |   |   |
 * 1 3              5   6   4
 * 0 3
 * 3 6
 *
 * out -> 0 2 4 1 5 3 6
 *
 */