#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    for (char ch : s) {
        x += ch == 'o';
        x -= ch == 'x';
        x = max(0, x);
    }
    cout << x << endl;

    return 0;
}