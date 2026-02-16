#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
bool vis_array[101];

void bfs(int src)
{
    queue<int> que;
    que.push(src);
    vis_array[src] = true;

    while (!que.empty()) // complexity O(N) = O(V) , Node = Vertex for graph
    {
        int par = que.front();
        que.pop();

        cout << par << " ";

        for (int child : adj_list[par]) // complexity O(edge)
        {
            if(!vis_array[child]) que.push(child);
            vis_array[child] = true;
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

    memset(vis_array, false, sizeof(vis_array)); // vis_array all value = false

    bfs(0); // total complexity = O(V + E)

    return 0;
}

/**
 * in ->
 * 7 7                                 0
 * 0 1                                 |
 * 1 3                                 1
 * 1 4                               /   \
 * 3 2                              3     4
 * 4 6                            /  \   /  \
 * 3 5                           2     5     6
 * 4 5 
 * 
 * out ->
 * 0 1 3 4 2 5 6 
 */