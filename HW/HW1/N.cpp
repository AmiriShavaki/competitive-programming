#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0, mi = 1000000009;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        mi = min(x, mi);
    }
    cout << (sum > (n - 1) * 100 ? sum - (n - 1) * 100 : 0) << ' ' << mi << endl;
}