#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353 
#define N 1003
 
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int rem0 = a[0] % 2;
        int rem1 = a[1] % 2;

        bool res = true;

        for (int i = 2; i < n; i++) {
            if (i % 2) {
                if (rem1 != a[i] % 2) res = false;
            } else {
                if (rem0 != a[i] % 2) res = false;
            }
        }

        cout << (res ? "YES" : "NO") << endl;
    }
 
    return 0;
}