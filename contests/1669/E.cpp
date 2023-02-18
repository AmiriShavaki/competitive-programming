#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353 
#define N 1000006 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int sz = 'k' - 'a' + 1;
        vector < vector <long long> > cnt(sz, vector <long long> (sz, 0));

        int n; 
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            cnt[s[0] - 'a'][s[1] - 'a']++;
        }

        long long res = 0;
        //Fix first character
        for (int i = 0; i < sz; i++) {
            for (int j1 = 0; j1 < sz; j1++) {
                for (int j2 = j1 + 1; j2 < sz; j2++) {
                    res += cnt[i][j1] * cnt[i][j2] + cnt[j1][i] * cnt[j2][i];
                }
            }
        }

        cout << res << endl;
    }
    return 0;
}