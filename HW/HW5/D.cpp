#include <iostream>

using namespace std;

#define N 100005
#define SQRT 100

int A[N];
long long dp[N][SQRT];
int n;

long long solve(int s, int k) {
    if (k >= SQRT) { // Calculate sum iteratively
        long long sum = 0;
        for (int i = s; i < n; i += k) sum += A[i];
        return sum;
    } else { // Just return preprocessed value
        return dp[s][k];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    // Preprocess
    for (int s = n - 1; s >= 0; s--) {
        for (int k = 1; k < SQRT; k++) {
            if (s + k < n) dp[s][k] = dp[s + k][k] + A[s];
            else dp[s][k] = A[s];
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int s, k; cin >> s >> k; s--;
        cout << solve(s, k) << '\n';
    }
    return 0;
}