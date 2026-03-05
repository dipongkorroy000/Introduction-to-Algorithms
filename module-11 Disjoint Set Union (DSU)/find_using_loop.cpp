#include <bits/stdc++.h>
using namespace std;

int par_ary[101];

int find(int node)
{

    while (par_ary[node] != -1) // complexity O(N)
    {
        cout << node << " ";
        node = par_ary[node];
    }

    return node;
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

    cout << find(4) << endl;

    return 0;
}