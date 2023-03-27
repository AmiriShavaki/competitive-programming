#include <bits/stdc++.h>
using namespace std;

#define N 1000006

vector <int> G[N];
int from[N], to[N];
int visited[N];

class DisjointSet{ public:
    vector<int> parent;
    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }
    void join(int a, int b) { parent[find(b)] = find(a); }
    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
    bool check(int a, int b){ return find(a) == find(b); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> from[i] >> to[i];
        G[from[i]].push_back(to[i]);
        G[to[i]].push_back(from[i]);
    }
    queue < pair<int, int> > q;
    queue <int> tq;
    DisjointSet dsu(n + 1);
    for (int i = 1; i <= k; i++) {
        int pos;
        cin >> pos;
        q.push(make_pair(pos, i));
        tq.push(0);
        visited[pos] = i;
    }
    int total = 0;
    while(!q.empty()) {
        pair <int,int> top = q.front(); q.pop();
        int topt = tq.front(); tq.pop();
        int v = top.first;
        int grp = top.second;
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            if (visited[u] != grp) {
                if (visited[u] == 0) {
                    visited[u] = grp;
                    q.push(make_pair(u, grp));
                    tq.push(topt + 1);
                } else {
                    if (!dsu.check(visited[u], grp)) {
                        dsu.join(visited[u], grp);
                        total++;
                        if (total == k - 1) {
                            cout << topt + 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}