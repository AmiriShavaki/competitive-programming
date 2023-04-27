#include <bits/stdc++.h>

using namespace std;

#define N 18

double a[N][N];
double dp[1 << N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
            
    for (unsigned int i = (1 << n) - 1; i >= 1; i--) {
        if (i == (1 << n) - 1) dp[i] = 1;
        for (int killer = 0; killer < n; killer++) {
            for (int victim = 0; victim < n; victim++) {
                if ( (i & (1 << killer)) && (i & (1 << victim)) && victim != killer ) {
                    dp[i & ~(1 << victim)] += (dp[i] * a[killer][victim]);
                } 
            }
        }
    }
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dp[1 << i];
    }

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6) << dp[1 << i] / sum << " \n"[i == n-1];
    }

    return 0;
}