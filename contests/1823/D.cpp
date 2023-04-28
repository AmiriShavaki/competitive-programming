#include <bits/stdc++.h>
using namespace std;

#define N 200005 
#define MAX 26
//#define int long long

char ans[N];
int x[MAX], c[MAX];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        string res = "YES";

        for (int i = 0; i < k; i++) cin >> x[i];
        for (int i = 0; i < k; i++) cin >> c[i];
        for (int i = 0; i < k; i++) {
            if (c[i] > x[i]) res = "NO";
            if (i && x[i] - x[i - 1] < c[i] - c[i - 1]) res = "NO";
        }
        if (res == "NO") {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; i++) ans[i] = 'a';
        int cur = 3;
        char ch = 'd';
        for (int i = 0; i < k; i++) {
            for (int j = x[i] - 1; j >= x[i] - 1 - (c[i] - cur - 1); j--) {
                ans[j] = ch;
            }
            ch++;
            cur = c[i];
        }
        cout << "YES\n";
        ch = 'a';
        for (int i = 0; i < n; i++) {
            if (ans[i] == 'a') {
                cout << ch++;
                if (ch == 'd') ch = 'a';
            } else cout << ans[i];
        } cout << endl;
    }
    return 0;
}