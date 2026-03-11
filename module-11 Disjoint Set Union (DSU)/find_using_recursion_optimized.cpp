#include <bits/stdc++.h>
using namespace std;

int par_ary[101];

int find(int node) // complexity O(logN)
{
    if (par_ary[node] == -1)
        return node;

    // cout << node << " ";

    int leader = find(par_ary[node]);

    par_ary[node] = leader; // every node parent update

    return leader;
}

int main()
{
    memset(par_ary, -1, sizeof(par_ary));

    par_ary[0] = 1;
    // par_ary[1] = -1;
    par_ary[2] = 1;
    par_ary[3] = 1;
    par_ary[4] = 5;
    par_ary[5] = 3;

    int leader = find(4);
    cout << leader << endl;

    // for (int i = 0; i < 6; i++)
    //     cout << i << " -> " << par_ary[i] << endl;

    return 0;
}

/**
 * clg -> 4 5 3 
 * 
 * out -> 1
 *
 * clg ->
 * 0 -> 1
 * 1 -> -1
 * 2 -> 1
 * 3 -> 1
 * 4 -> 1
 * 5 -> 1
 *
 */