#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353 
#define N 200005 
 
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flg = false;
        vector <int> cnt(n + 5, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (!flg && ++cnt[a[i]] >= 3) {
                flg = true;
                cout << a[i] << endl;
            }
        }
        if (!flg) cout << "-1\n";
    }
 
    return 0;
}