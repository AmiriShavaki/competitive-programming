#include<bits/stdc++.h>

using namespace std;

#define N 100005

int chl_cnt[N];
vector <int> G[N];
bool visited[N];

void dfs(int v, int par=-1) {
    visited[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!visited[G[v][i]]) {
            dfs(G[v][i], v);
        }
    }
    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] != par) {
            chl_cnt[v] += chl_cnt[G[v][i]] + 1;
        }
    }
}

int main() {
    int n; cin >> n;
    if (n % 2) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int from, to; cin >> from >> to; from--; to--;
        G[to].push_back(from);
        G[from].push_back(to);
    }
    dfs(0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += chl_cnt[i] % 2 && i;
        // cout << chl_cnt[i] << endl;
    }
    cout << ans;
}