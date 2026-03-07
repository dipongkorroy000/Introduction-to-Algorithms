#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int> pri_que; // max value on the top();

    // priority_queue<int, vector<int>, greater<int>> pri_que; // min value on the top();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pri_que; // pair according first value on the top();

    pri_que.push({10, 1});
    pri_que.push({5, 2});

    cout << pri_que.top().first << " " << pri_que.top().second << endl; // out -> 5 2

    return 0;
}