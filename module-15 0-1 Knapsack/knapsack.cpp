#include <bits/stdc++.h>
using namespace std;

int val_ary[1001], weight_ary[1001];

int knapsack(int i, int bag_limit)
{
    if (i < 0 || bag_limit <= 0)
        return 0;

    if (weight_ary[i] <= bag_limit)
    {
        int op1 = knapsack(i - 1, bag_limit - weight_ary[i]) + val_ary[i];
        int op2 = knapsack(i - 1, bag_limit);
        return max(op1, op2);
    }
    else
    {
        int op2 = knapsack(i - 1, bag_limit);
        return op2;
    }
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val_ary[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight_ary[i];
    }

    int bag_limit;
    cin >> bag_limit;

    int val = knapsack(n - 1, bag_limit); // complexity O(2^N)

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