#include <bits/stdc++.h>
using namespace std;

int par_ary[101];
int group_size[101];

int find(int node) // complexity O(logN)
{
    if (par_ary[node] == -1) return node;

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

    dsu_union(1, 2);
    dsu_union(2, 0);
    dsu_union(3, 1);

    int leader = find(4);
    cout << leader << endl;

    // for (int i = 0; i < 6; i++)
    //     cout << i << " -> " << par_ary[i] << endl;

    return 0;
}

/**
 * out -> 4
 *
 * clg ->
 * 0 -> 1
 * 1 -> -1
 * 2 -> 1
 * 3 -> 1
 * 4 -> -1
 * 5 -> -1
 *
 */