#include <bits/stdc++.h>

using namespace std;

#define N 502
#define MOD 1000000007
#define int long long

long long inv[N], fact[N], fact_inv[N];
int a[N], dp[N][N];

inline long long comb(int k, int n) {
    return fact[n] * fact_inv[n-k] % MOD * fact_inv[k] % MOD;
}

int32_t main() {
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

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // Base case
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = a[i] > a[i + 1];
        dp[i + 1][i] = 1;
    } dp[n][n - 1] = 1;

    for (int len = 4; len <= n; len += 2) {
        for (int st = 0; st < n + 1 - len; st++) {
            int ed = st + len - 1;
            for (int cut = st + 1; cut <= ed; cut += 2) { 
                if (a[st] <= a[cut]) continue;
                dp[st][ed] += dp[st + 1][cut - 1] * dp[cut + 1][ed] % MOD * comb(
                    (cut - (st - 1)) / 2, (ed - (st - 1)) / 2
                ) % MOD;
                dp[st][ed] %= MOD;
                //if (st == 0 && ed == 5) cout << "Debug "  << dp[st + 1][cut - 1] << ' ' <<  dp[cut + 1][ed] << endl;              
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " \n"[j == n - 1];
    //     }
    // }

    cout << dp[0][n - 1];
}