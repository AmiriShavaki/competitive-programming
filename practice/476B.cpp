#include <bits/stdc++.h>

using namespace std;

#define N 25

int dp[N][N]; //dp[length][pos]

int32_t main() {
    string s1, s2;
    cin >> s1 >> s2;

    int finalpos = 11; // everything shifted by 11 to avoid negative coordinates
    for (char c: s1) {
        finalpos += c == '+' ? 1 : -1;
    }

    dp[0][11] = 1;
    for (int len = 1; len <= s2.size(); len++) {
        char c = s2[len-1];
        for (int pos = 1; pos < N - 1; pos++) {
            if (c != '-') { // + ?
                dp[len][pos] += dp[len - 1][pos-1];
            } 
            if (c != '+') { // - ?
                dp[len][pos] += dp[len - 1][pos+1];
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += dp[s2.size()][i];
    }
    
    cout << setprecision(10) << (double) dp[s2.size()][finalpos] / sum;
}