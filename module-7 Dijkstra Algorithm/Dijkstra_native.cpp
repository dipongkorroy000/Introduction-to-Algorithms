#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_list[101]; // 0|{1, 10}, {2, 7}, {3, 4} |
                                      // 1|{0, 10}, {4, 3}, {2, 1} |
int dis_ary[101];                     // 2|{0, 7},  {1, 1}, {4, 5}, {3, 1} |
                                      // 3|{0, 4},  {2, 1}, {4, 5} |
void dijkstra(int src)                // 4|{1, 3},  {2, 5}, {3, 5} |
{
    queue<pair<int, int>> que;
    que.push({src, 0});

    dis_ary[src] = 0;

    while (!que.empty())
    {
        pair<int, int> par = que.front();
        que.pop();

        int par_node = par.first;
        int par_dis = par.second;

        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (par_dis + child_dis < dis_ary[child_node])
            {
                dis_ary[child_node] = par_dis + child_dis;
                que.push({child_node, dis_ary[child_node]});
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
        int a, b, w;
        cin >> a >> b >> w;

        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});
    }

    for (int i = 0; i < n; i++)
        dis_ary[i] = INT_MAX;

    dijkstra(0); // source = 0;

    for (int i = 0; i < n; i++)
        cout << "0 to " << i << " shortest distance : " << dis_ary[i] << endl;

    return 0;
}

/** Dijkstra native like BFS
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
 *                      source = 0
 * 
 * out -> single source shortest distances =
 * 0 to 0 shortest distance : 0
 * 0 to 1 shortest distance : 6
 * 0 to 2 shortest distance : 5
 * 0 to 3 shortest distance : 4
 * 0 to 4 shortest distance : 9
 *
 */