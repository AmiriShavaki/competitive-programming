#include <bits/stdc++.h>

using namespace std;

#define N 200005

vector <int> G[N], dp[N];
vector <bool> is_out[N];

int go(int v, int u_ind) {

    if (dp[v][u_ind] != -1) return dp[v][u_ind];

    dp[v][u_ind] = 1 - is_out[v][u_ind];
    int u = G[v][u_ind];
    for (int i = 0; i < G[u].size(); i++) {
        if (G[u][i] == v) continue;
        if (dp[u][i] != -1) dp[v][u_ind] += dp[u][i];
        else dp[v][u_ind] += go(u, i);
    }
    return dp[v][u_ind];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int from, to; 
        cin >> from >> to; 
        from--; to--;

        G[from].push_back(to);
        G[to].push_back(from);
        is_out[from].push_back(true);
        is_out[to].push_back(false);
        dp[from].push_back(-1);
        dp[to].push_back(-1);
    }

    vector <int> ans_vec;

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) { // i is vertex
        int cur = 0;
        for (int j = 0; j < dp[i].size(); j++) { // j is vertex index
            if (dp[i][j] == -1) {
                go(i, j);
            }
            //cout << "dp " << i << ' ' << G[i][j] << ' ' << dp[i][j] << endl;
            cur += dp[i][j];
        }
        if (cur < ans) {
            ans_vec.clear();
            ans_vec.push_back(i + 1);
            ans = cur;
        } else if (cur == ans) ans_vec.push_back(i + 1);
    }

    cout << ans << endl;
    for (int i = 0; i < ans_vec.size(); i++) cout << ans_vec[i] << " \n"[i == ans_vec.size() - 1];
    return 0;
}