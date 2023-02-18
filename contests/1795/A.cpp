#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        reverse(s2.begin(), s2.end());
        string res = "YES";

        bool flg = false;
        for (int i = 1; i < n; i++) {
            if (!flg) {
                if (s1[i - 1] == s1[i]) {
                    flg = true;
                }
            } else {
                if (s1[i - 1] == s1[i]) {
                    res = "NO";
                }
            }
        }
        for(int i = 0; i < m; i++) {
            char prev;
            if (i == 0) {
                prev = s1[n - 1];
            } else {
                prev = s2[i - 1];
            }

            if (!flg) {
                if (prev == s2[i]) {
                    flg = true;
                }
            } else {
                if (prev == s2[i]) {
                    res = "NO";
                }
            }            
        }
        cout << res << endl;
    }
    return 0;
}