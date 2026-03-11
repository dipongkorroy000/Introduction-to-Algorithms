#include <bits/stdc++.h>
using namespace std;

int par_ary[101];
int group_size[101];

int find(int node) // complexity O(logN)
{
    if (par_ary[node] == -1)
        return node;

    int leader = find(par_ary[node]);

    par_ary[node] = leader;

    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (group_size[leader2] <= group_size[leader1])
    {
        par_ary[leader2] = leader1;

        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par_ary[leader1] = leader2;

        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    memset(par_ary, -1, sizeof(par_ary));
    memset(group_size, 1, sizeof(group_size));

    int n, e;
    cin >> n >> e;

    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
            cycle = true;
        else
            dsu_union(a, b);
    }

    if (cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}

/**
 * in ->
 * 6 6
 * 0 1
 * 1 2
 * 0 4
 * 4 5
 * 5 3
 * 3 4
 *
 * out ->
 * Cycle detected
 */