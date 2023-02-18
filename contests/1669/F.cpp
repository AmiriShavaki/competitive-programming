#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353 
#define N 200005 
 
int w[N], lsum[N], rsum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
 
        for (int i = 0; i < n; i++) cin >> w[i];

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        lsum[0] = w[0];
        rsum[n - 1] = w[n - 1];

        for (int i = 1; i < n; i++) {
            lsum[i] = lsum[i - 1] + w[i];
            rsum[n - 1 - i] = rsum[n - i] + w[n - i - 1];
        }

        int lind = 0; //current candid to eat
        int rind = n - 1; //current candid to eat

        int late = 0;
        int rate = 0;

        int total_ate = 0, ans = 0;
        while (lind <= rind) {
            if (late == rate) {
                ans = total_ate;
                late = lsum[lind++];
                total_ate++;
            } else if (late > rate) {
                rate = rsum[rind--];
                total_ate++;
            } else {
                late = lsum[lind++];
                total_ate++;
            }
        }
        if (late == rate) ans = total_ate;
        cout << ans << endl;
    }
 
    return 0;
}