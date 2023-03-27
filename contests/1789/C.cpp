#include <bits/stdc++.h>
using namespace std;

#define N 200005

int a[N];

void debug(map < int, int >& cnt) {
    map < int, int >::iterator it = cnt.begin();
    cout << "***Debug***\n";
    for (; it != cnt.end(); it++) {
        cout << it -> first << ' ' << it -> second << endl;
    }
    cout << "***End of Debug***\n";
}

void add_cnt(map < int, int >& cnt, int pos, int cur, vector<int>& st_time) {
    int inc = cur - st_time[pos];
    if (cnt.find(a[pos]) == cnt.end()) {
        cnt[a[pos]] = inc;
    } else {
        cnt[a[pos]] += inc;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        map < int, int > cnt;
        int n, m;
        cin >> n >> m;
        vector <int> st_time(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            int p_i, v_i;
            cin >> p_i >> v_i;
            p_i--; //0-based
            if (a[p_i] == v_i) { //nothing changes
                continue;
            }
            add_cnt(cnt, p_i, i + 1, st_time);
            st_time[p_i] = i + 1;
            a[p_i] = v_i;
        }
        //debug(cnt);
        for (int i = 0; i < n; i++) {
            add_cnt(cnt, i, m + 1, st_time);
        }
        //debug(cnt);
        long long ans = 0;
        for (int i = 1; i < n + m + 1; i++) {
            if (cnt.find(i) == cnt.end()) continue;
            ans += ((long long) m + 1 - cnt[i]) * cnt[i];
            ans += ((long long)cnt[i]) * (cnt[i] - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}