#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        string s; cin >> s;
        map <char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int evcnt = 0, od = 0;
        for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            evcnt += 1 - (it->second % 2);
            if (it->second % 2) od = it->second;
        }
        if (evcnt > 1 || od > 1 && evcnt) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}