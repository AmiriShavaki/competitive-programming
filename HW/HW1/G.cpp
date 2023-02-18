#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int c_i;
        cin >> c_i;
        sum += c_i;
    }
    cout << (sum >= k ? "YES" : "NO");

    return 0;
}