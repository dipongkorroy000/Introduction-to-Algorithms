#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool vis_ary[101];
int level_ary[101];
int par_ary[101];

void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis_ary[src] = true;
    level_ary[src] = 0;

    while (!que.empty())
    {
        int par = que.front();
        que.pop();

        for (int child : adj_list[par])
        {
            if (!vis_ary[child])
            {
                que.push(child);
                vis_ary[child] = true;
                level_ary[child] = level_ary[par] + 1;
                par_ary[child] = par;
            }
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

    memset(vis_ary, false, sizeof(vis_ary));  // vis_ary all value = false
    memset(level_ary, -1, sizeof(level_ary)); // level_ary all value = -1
    memset(par_ary, -1, sizeof(par_ary));     // par_ary all value = -1

    int src, dst;
    cin >> src >> dst;

    bfs(src);

    int node = dst;
    vector<int > path_vec;

    while (node != -1)
    {
        // cout << node << " ";
        path_vec.push_back(node);
        node = par_ary[node];
    }

    reverse(path_vec.begin(), path_vec.end());

    for(int x : path_vec){
        cout << x << " ";
    }

    return 0;
}

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
 * 5
 *
 * out -> 0 1 3 5
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
 * out -> 6
 *
 *
 */