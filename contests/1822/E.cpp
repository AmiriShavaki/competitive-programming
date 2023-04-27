#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = numeric_limits<int>::max();
        if (n & 1) {
            ans = -1;
        }
        map <char, int> ch_cnt; for (char c = 'a'; c <= 'z'; c++) ch_cnt[c] = 0;
        for (char c : s) {
            ch_cnt[c]++;
            if (ch_cnt[c] > n / 2) ans = -1;
        }
        if (ans == -1) {
            cout << "-1\n"; continue;
        }
        map <char, int> cnt_eq; for (char c = 'a'; c <= 'z'; c++) cnt_eq[c] = 0;
        int ma = 0, sum = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == s[n - i - 1]) {
                cnt_eq[s[i]]++;
                ma = max(ma, cnt_eq[s[i]]);
                sum++;
            }
        }
        if (ma > sum - ma) cout << ma;
        else cout << sum / 2 + sum % 2;
        cout << endl;
    }
    return 0;
}