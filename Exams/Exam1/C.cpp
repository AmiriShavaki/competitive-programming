#include <bits/stdc++.h>
using namespace std;

#define N 1000006
#define MOD 1000000007

int pr_pwr[N];

void factorize(int n) {
    int div = 2;
    while (n > 1 && div * div <= n) {
        while (n % div == 0) {
            n /= div;
            pr_pwr[div]++;
        }
        div++;
    }
    if (n > 1) pr_pwr[n]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = a + 1; i <= b; i++) {
        factorize(i);
    }
    long long ans = 1;
    for (int i = 0; i < b + 1; i++) {
        ans = ans * (pr_pwr[i] + 1) % MOD;
    }
    cout << ans;
    return 0;
}