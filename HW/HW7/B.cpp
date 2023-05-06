#include <bits/stdc++.h>
using namespace std;

#define N 50004
//#define int long long

string adj_mat[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_mat[i][j] = '0';
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj_mat[u][v] = '1';
        adj_mat[v][u] = '1';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_mat[i][j];
        } cout << endl;
    }
    return 0;
}