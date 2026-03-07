#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool vis_array[101];

void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis_array[src] = true;

    while (!que.empty())
    {
        int par = que.front();
        que.pop();

        cout << par << " ";

        for (int child : adj_list[par])
        {
            if (!vis_array[child])
            {
                que.push(child);
                vis_array[child] = true;
            }
        }
    }

    cout << endl;
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

    memset(vis_array, false, sizeof(vis_array));

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    if (vis_array[dst])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

/**
 * in ->
 * 7 5                                 0
 * 0 1                                 |
 * 1 3                                 1
 * 3 2                               /
 * 4 6                              3     4
 * 3 5                            /  \      \
 * 0                             2     5     6
 * 4
 *
 * out ->
 * 0 1 3 2 5
 * NO
 */