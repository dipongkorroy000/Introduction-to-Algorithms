#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool vis_ary[101];
int par_ary[101];
bool cycle;

void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis_ary[src] = true;

    while (!que.empty())
    {
        int par = que.front();
        que.pop();

        for (int child : adj_list[par])
        {
            if (vis_ary[child] == true && par_ary[par] != child)
                cycle = true;

            if (vis_ary[child] == false)
            {
                que.push(child);
                vis_ary[child] = true;
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
    
    memset(vis_ary, false, sizeof(vis_ary));
    memset(par_ary, -1, sizeof(par_ary));
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (vis_ary[i] == false)
            bfs(i);
    }

    if (cycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}

/**
 * in ->
 * 4 4                  nodes 4 , edges 4
 * 0 1                          0
 * 1 2                        /   \
 * 2 3                       1     3
 * 3 0                        \   /
 *                              2
 * out ->
 * Cycle Detected
 *
 */