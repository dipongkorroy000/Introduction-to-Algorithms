#include <bits/stdc++.h>
using namespace std;

char grid_ary[101][101];
bool vis_ary[101][101];
int level_ary[101][101];
vector<pair<int, int>> move_vec = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid_check(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> que;
    que.push({si, sj});
    vis_ary[si][sj] = true;
    level_ary[si][sj] = 0;

    while (!que.empty())
    {
        pair<int, int> par = que.front();
        int par_i = par.first;
        int par_j = par.second;
        que.pop();

        // cout << par_i << " " << par_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + move_vec[i].first;
            int cj = par_j + move_vec[i].second;

            if (vis_ary[ci][cj] == false && valid_check(ci, cj))
            {
                que.push({ci, cj});
                vis_ary[ci][cj] = true;
                level_ary[ci][cj] = level_ary[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid_ary[i][j];

    memset(vis_ary, false, sizeof(vis_ary));
    memset(level_ary, -1, sizeof(level_ary));

    int si, sj; // source i, source j
    cin >> si >> sj;

    int dst_i, dst_j;
    cin >> dst_i >> dst_j;

    bfs(si, sj);

    cout << "destination = " << level_ary[dst_i][dst_j] << endl;

    return 0;
}

/**
 * in ->
 * | 3 4
 * | * * * *
 * | * * * *
 * | * * * *
 * | 1 2
 * | 2 0
 *
 * out ->
 * 1 2
 * 0 2
 * 2 2
 * 1 1
 * 1 3
 * 0 1
 * 0 3
 * 2 1
 * 2 3
 * 1 0
 * 0 0
 * 2 0
 * or -> 
 * destination = 3
 */