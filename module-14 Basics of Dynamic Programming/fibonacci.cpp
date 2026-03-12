#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    cout << fibonacci(10) << endl; // 55 complexity ~ O(2^N)
    return 0;
}

/**
 * explanation: 
 * fibonacci series -> 0 1 1 2 3 5 8 13 21 34 55.....
 * 0, 1 fixed, next = 0 + 1 = 1, next = 1 + 1 = 2, next = 1 + 2 = 3 
 * 
 * Naive recursion (without memoization) → O(2^N)
 */