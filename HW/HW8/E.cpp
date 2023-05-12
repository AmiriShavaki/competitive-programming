#include <bits/stdc++.h>
using namespace std;

#define N 2000
#define int long long

vector <int> G[N];
int a[N];
bool visited[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int v, u; cin >> v >> u; v--; u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    for (int pashmak = 0; pashmak < n; pashmak++) {
        priority_queue< pair<int, int> > candids; // < -a_i, i > 
        int pwr = a[pashmak], ans = 0;
        memset(visited, 0, sizeof(visited));
        visited[pashmak] = true;

        for (int i = 0; i < G[pashmak].size(); i++) {
            int u = G[pashmak][i];
            if (!visited[u]) {
                visited[u] = true;
                candids.push(make_pair(-a[u], u));
            }
        }

        while (!candids.empty()) {
            pair<int, int> top = candids.top(); candids.pop();
            int best_ai = -top.first, best_i=top.second;
            if (pwr + ans > best_ai) { // Sauleh is powerful enough
                pwr += best_ai;
                // cout << "pwr " << pwr << endl;
            } else { // Sauleh is not powerful enough
            // if (pashmak == 5) cout << "DEBUG " << ans << " " << pwr << endl;
                ans += best_ai - (pwr + ans) + 1;
                pwr += best_ai;
            }
            for (int i = 0; i < G[best_i].size(); i++) {
                int u = G[best_i][i];
                if (!visited[u]) {
                    candids.push(make_pair(-a[u], u));
                    visited[u] = true;
                }
            }
        }
        cout << ans << " \n"[pashmak == n - 1];
    }
    return 0;
}