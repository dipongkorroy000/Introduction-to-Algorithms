#include <bits/stdc++.h>
using namespace std;

int val_ary[1001], weight_ary[1001];
int dp_ary[1001][1001];

int knapsack(int i, int bag_limit)
{
    if (i < 0 || bag_limit <= 0)
        return 0;

    if (dp_ary[i][bag_limit] != -1)
        return dp_ary[i][bag_limit];

    if (weight_ary[i] <= bag_limit)
    {
        int op1 = knapsack(i - 1, bag_limit - weight_ary[i]) + val_ary[i];
        int op2 = knapsack(i - 1, bag_limit);
        dp_ary[i][bag_limit] = max(op1, op2);
        return dp_ary[i][bag_limit];
    }
    else
    {
        dp_ary[i][bag_limit] = knapsack(i - 1, bag_limit);
        return dp_ary[i][bag_limit];
    }
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val_ary[i];
    for (int i = 0; i < n; i++)
        cin >> weight_ary[i];

    int bag_limit;
    cin >> bag_limit;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= bag_limit; j++)
            dp_ary[i][j] = -1;

    int val = knapsack(n - 1, bag_limit); // complexity O(N * W)

    cout << "max bag weight catch = " << val << endl;

    return 0;
}

/**
 * in ->
 * 4
 * 10 4 7 5
 * 4 3 2 5
 * 8
 *
 * out -> max bag weight catch = 17
 */