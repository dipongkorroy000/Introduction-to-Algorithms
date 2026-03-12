#include <bits/stdc++.h>
using namespace std;

long long int dp_ary[1001];

long long int fibonacci(long long int n)
{
    if (n == 0 || n == 1) return n;

    if (dp_ary[n] != -1) return dp_ary[n];

    dp_ary[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return dp_ary[n];
}

int main()
{
    memset(dp_ary, -1, sizeof(dp_ary));

    cout << fibonacci(100) << endl; // 3736710778780434371 complexity ~ O(N)
    return 0;
}

/**
 * explanation:
 * fibonacci series -> 0 1 1 2 3 5 8 13 21 34 55.....
 * 0, 1 fixed, next = 0 + 1 = 1, next = 1 + 1 = 2, next = 1 + 2 = 3
 * 
 * Top-Down (Memoization): Uses recursion with a cache (e.g., std::vector) to store results of subproblems.
 *
 */