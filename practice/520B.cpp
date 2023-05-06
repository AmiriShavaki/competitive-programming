#include <bits/stdc++.h>
using namespace std;

#define N 20004

bool visited[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    queue <int> q_val, q_ans;
    q_val.push(n);
    q_ans.push(0);

    while(true) {
        int top_val = q_val.front(), top_ans = q_ans.front(); 
        q_val.pop(); q_ans.pop();
        visited[top_val] = true;

        if (top_val == m) {
            cout << top_ans << endl;
            return 0;
        }
        if (top_val - 1 >= 0 && !visited[top_val - 1]) {
            q_val.push(top_val - 1);
            q_ans.push(top_ans + 1);
        }
        if (top_val * 2 < N && !visited[top_val * 2]) {
            q_val.push(top_val * 2);
            q_ans.push(top_ans + 1);
        }
    }
}