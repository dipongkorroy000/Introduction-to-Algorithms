#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int dis_ary[101];
vector<Edge> edge_list;
int n, e;

void bellman_ford()
{
    for (int i = 0; i < n - 1; i++) // complexity O(V)
    {
        for (auto obj : edge_list) // complexity O(E)
        {
            int a = obj.a, b = obj.b, w = obj.w;

            if (dis_ary[a] != INT_MAX && dis_ary[a] + w < dis_ary[b])
            {
                dis_ary[b] = dis_ary[a] + w;
            }
        }
    }

    bool cycle = false;

    for (auto obj : edge_list) // complexity O(E)
    {
        int a = obj.a, b = obj.b, w = obj.w;

        if (dis_ary[a] != INT_MAX && dis_ary[a] + w < dis_ary[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative weighted cycle detected" << endl;
    else
    {
        // cout << "No negative weighted cycle" << endl;
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis_ary[i] << endl;
    }
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        Edge obj = Edge(a, b, w);
        edge_list.push_back(obj);

        // edge_list.push_back(Edge(b, a, w)); // undirected graph
    }

    for (int i = 0; i < n; i++)
        dis_ary[i] = INT_MAX;

    dis_ary[0] = 0;

    bellman_ford(); // total complexity O(V * E)

    return 0;
}

/**
 * in ->                  3
 * 4 4              2 --------- 1
 * 0 2 5            |           |
 * 0 3 12         5 |           | 3
 * 2 1 2            |     12    |
 * 1 3 3            0 --------- 3
 *
 * out ->
 * 0 -> 0
 * 1 -> 7
 * 2 -> 5
 * 3 -> 10
 *
 *
 * in ->
 * 4 4                  0
 * 0 1 5                | 5
 * 1 2 3                1
 * 2 3 2            3 /   \ -6
 * 3 1 -6            2 --- 3
 *                      2
 * out -> Negative weighted cycle detected

 * in ->
 * 4 4                  0
 * 0 1 5                | 5
 * 1 2 3                1
 * 2 3 2            3 /   \ -2
 * 3 1 -2            2 --- 3
 *                      2
 * out ->
 * 0 -> 0
 * 1 -> 5
 * 2 -> 8
 * 3 -> 10
 * 
 */