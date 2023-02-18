#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a, b;
    a = 1;
    b = 1;
    for (int i = 1; i <= n; i++) {
        if (i < b) cout << '-';
        else {
            cout << '+';
            
            int tmp = b;
            b += a;
            a = tmp;
        }
    }

    return 0;
}