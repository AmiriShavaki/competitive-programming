#include <bits/stdc++.h>

using namespace std;

#define N 20004
#define K 502

vector <int> G[N], dp[N][K];

int go(int v, int i, int u_ind) {
    if (dp[v][i][u_ind] != -1) return dp[v][i][u_ind];

    int u = G[v][u_ind];
    dp[v][i][u_ind] = 0;

    for (int j = 0; j < G[u].size(); j++) {
        if (G[u][j] == v) continue;
        dp[v][i][u_ind] += go(u, i-1, j);
    }
    return dp[v][i][u_ind];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    

    int n, k; cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b; 
        cin >> a >> b; 
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);

        dp[a][1].push_back(1);
        dp[b][1].push_back(1);
        for (int i = 2; i <= k; i++) {
            dp[a][i].push_back(-1);
            dp[b][i].push_back(-1);
        }
    }

    for (int i = 2; i <= k; i++) {
        for (int v = 0; v < n; v++) {
            for (int u_ind = 0; u_ind < G[v].size(); u_ind++) {
                if (dp[v][i][u_ind] == -1) go(v, i, u_ind);
            }
        }
    }

    int sum = 0;
    for (int v = 0; v < n; v++) {
        for (int u_ind = 0; u_ind < G[v].size(); u_ind++) {
            sum += dp[v][k][u_ind];
        }
    }

    cout << sum / 2;
    return 0;
}