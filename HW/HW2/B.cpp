#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> pref(n, 0), suff(n, 0);
        set<char> s1, s2;
        int ans = numeric_limits<int>::min();
        for (int i = 0; i < s.size(); i++) {
            s1.insert(s[i]);
            pref[i] = s1.size();
            suff[s.size() - 1 - i] = s2.size();
            s2.insert(s[s.size() - 1 - i]);
        }
        for (int i = 0; i < s.size(); i++) ans = max(ans, pref[i] + suff[i]);
        cout << ans << endl;
    }

    return 0;
}