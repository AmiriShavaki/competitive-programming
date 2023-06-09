#include <bits/stdc++.h>

using namespace std;

#define N 100005

vector <int> G[N];
vector<int> chld_cnt[N];
vector<bool> visited[N];
vector < pair< pair<int, pair<int, int> >, int > > E;

void dfs(int v) {
    for (int i = 0; i < G[v].size(); i++) {
        if (!visited[v][i]) {
            visited[v][i] = true;
            dfs(G[v][i]);
        }
    }
    for (int i = 0; i < G[v].size(); i++) {
        for (int j = 0; j < G[G[v][i]].size(); j++) {
            if (G[G[v][i]][j] == v) continue;
            chld_cnt[v][i] += 1 + chld_cnt[G[v][i]][j];
        }
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, f; cin >> u >> v >> f; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        chld_cnt[u].push_back(0);
        chld_cnt[v].push_back(0);
        visited[u].push_back(false);
        visited[v].push_back(false);
        E.push_back(make_pair(make_pair(f, make_pair(v, u)), i));
    }
    sort(E.begin(), E.end());
    reverse(E.begin(), E.end());
    for (int i = 0; i < n - 1; i++) {
        dfs(E[i].first.second.first);
        dfs(E[i].first.second.second);
    }
}