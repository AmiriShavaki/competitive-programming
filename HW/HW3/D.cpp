#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;
    if (l > r) {
        swap(l, r);
    }
    int cur = 0;
    vector <int> segs;
    for (int i = l - 1; i <= r - 1; i++) {
        if (s[i] == 'H') {
            cur++;
        } else if (cur) {
            segs.push_back(cur);
            cur = 0;
        }
    }
    if (cur) {
        segs.push_back(cur);
    }
    int ans = 0;
    for (int i = 0; i < segs.size(); i++) {
        while(segs[i]) {
            segs[i] -= 1 << __lg(segs[i]);
            ans++;
        }   
    }
    cout << ans;

    return 0;
}