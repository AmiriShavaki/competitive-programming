#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    set<int> digits;
    set<int>::iterator it;
    while (n) {
        it = digits.find(n % 10);
        if (it != digits.end()) {
            return false;
        }
        digits.insert(n % 10);
        n /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int y;
    cin >> y;

    int ans;
    for (ans = y + 1; !check(ans); ans++) {;}
    cout << ans << endl;

    return 0;
}