#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool vis_array[101];
int level_array[101];

void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis_array[src] = true;
    level_array[src] = 0;

    while (!que.empty())
    {
        int par = que.front();
        que.pop();

        // cout << par << " ";

        for (int child : adj_list[par])
        {
            if (!vis_array[child])
            {
                que.push(child);
                vis_array[child] = true;
                level_array[child] = level_array[par] + 1;
            }
        }
    }
    // cout << endl;
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

    memset(vis_array, false, sizeof(vis_array));  // vis_array all value = false
    memset(level_array, -1, sizeof(level_array)); // level array all value = -1

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> " << level[i] << endl;
    // }

    cout << "distance = " << level_array[dst] << endl;

    return 0;
}

/**
 * in -> node = 7 edge = 8
 * 7 8
 * 0 1                      0        level = 0
 * 1 3                      |
 * 1 4                      1        level = 1
 * 3 2                    /   \
 * 2 5                   3     4     level = 2
 * 3 5                 /   \   |
 * 4 6                2-----5--6     level = 3
 * 5 6
 * 0
 *
 *
 * out ->
 * 0 -> 0
 * 1 -> 1
 * 2 -> 3
 * 3 -> 2
 * 4 -> 2
 * 5 -> 3
 * 6 -> 3
 */

/**
 * in -> node = 7 edge = 8
 * 7 8
 * 0 1
 * 1 3
 * 1 4                      0        level = 0
 * 3 2                      |
 * 2 5                      1        level = 1
 * 3 5                    /   \
 * 4 6                   3     4     level = 2
 * 5 6                 /   \   |
 * 0                  2-----5--6     level = 3
 * 4
 *
 * out ->
 * distance = 2
 *
 *
 * in ->
 * 5 4                  0
 * 0 1                  |
 * 1 3                  1
 * 1 4                /   \
 * 3 2               3     4
 * 5 6              /
 * 0               2        5---6
 * 5
 *
 * out -> no connection
 * distance = -1
 *
 *
 */