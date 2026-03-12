#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int fibonacci[1001];

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for(int i = 2; i <= 100; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    };

    cout << fibonacci[100] << endl;

    return 0;
}

/**
 * explanation:
 * fibonacci series -> 0 1 1 2 3 5 8 13 21 34 55.....
 * 0, 1 fixed, next = 0 + 1 = 1, next = 1 + 1 = 2, next = 1 + 2 = 3
 *
 * Bottom-up DP → O(N) (আরও efficient, stack overflow নেই)
 *
 */