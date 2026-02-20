#include <bits/stdc++.h>
using namespace std;

char grid_ary[101][101];
bool vis_ary[101][101];
vector<pair<int, int>> move_vec = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid_check(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis_ary[si][sj] = true;

    for (int i = 0; i < 4; i++) // complexity O(V) = O(n*m)
    {
        int ci, cj;
        ci = si + move_vec[i].first;
        cj = sj + move_vec[i].second;

        if (vis_ary[ci][cj] == false && valid_check(ci, cj) == true)
            dfs(ci, cj);
    }

    return;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid_ary[i][j];

    int si, sj; // source i, source j
    cin >> si >> sj;

    memset(vis_ary, false, sizeof(vis_ary));

    dfs(si, sj);

    return 0;
}

/**
 * in ->
 * | 3 4
 * | * * * *
 * | * * * *
 * | * * * *
 * | 1 2
 *
 * out ->
 * 1 2
 * 0 2
 * 0 1
 * 1 1
 * 2 1
 * 2 0
 * 1 0
 * 0 0
 * 2 2
 * 2 3
 * 1 3
 * 0 3
 */