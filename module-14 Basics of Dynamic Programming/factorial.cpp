// factorial sign -> !
#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n == 1) return 1;

    int mul = factorial(n-1);

    return n * mul;
}

int main()
{
    cout << factorial(5) << endl; // complexity O(N)
    return 0;
}

/**
 * out -> 120
 * 
 * explanation :
 *  5 factorial means ->
 *  5! = 5 * 4 * 3 * 2 * 1 = 120
 *  5! = 5 * 4! = 120
 */