#include <bits/stdc++.h>
using namespace std;

#define N 1000006

bool is_prime[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    fill(is_prime, is_prime + N, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i + i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += is_prime[i];
    cout << ans << endl; 
    return 0;
}