#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define MOD 998244353

long long inv[N], fact[N], fact_inv[N];

inline long long comb(int k, int n) {
    return fact[n] * fact_inv[n-k] % MOD * fact_inv[k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	inv[1] = 1;
	for(int i = 2; i < N; i++) {
		inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
	}
	fact[0] = 1; 
	fact_inv[0] = 1; 
	for(int i = 1; i < N; i++) {
		fact[i] = fact[i-1]*i % MOD;
		fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
	}

    int n;
    cin >> n;
    long long ans = comb(n / 6, n / 3);

    for (int i = 0; i < n / 3; i++) {
        int w[3];
        cin >> w[0] >> w[1] >> w[2];
        sort(w, w + 3);
        if (w[0] == w[1] && w[1] == w[2]) {
            ans = (ans * 3) % MOD;
        } else if (w[0] == w[1]) {
            ans = (ans * 2) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}