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

    for (int i = 0; i < n; i++)
        cout << "0 to " << i << " -> " << dis_ary[i] << endl;

    return 0;
}

/**
 * in ->                  2
 * 4 4              2 --------- 1
 * 0 2 5            |           |
 * 0 3 12         5 |           | 3
 * 2 1 2            |     12    |
 * 1 3 3            0 --------- 3
 *
 * out ->
 * 0 to 0 -> 0
 * 0 to 1 -> 7
 * 0 to 2 -> 5
 * 0 to 3 -> 10
 * 
 * 
 * in ->
 * 4 4                  0
 * 0 1 5                | 5
 * 1 2 3                1
 * 2 3 2            3 /   \ -6
 * 3 1 -6            2 --- 3
 *                      2
 * out ->
 * 0 to 0 -> 0
 * 0 to 1 -> 2
 * 0 to 2 -> 6
 * 0 to 3 -> 8
 */