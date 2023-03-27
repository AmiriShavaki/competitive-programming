#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int pos_cnt = 0, neg_cnt = 0;
    while(n--) {
        int a_i;
        cin >> a_i;
        pos_cnt += a_i >= 0;
        neg_cnt += a_i < 0;
    }
    cout << neg_cnt * (pos_cnt + neg_cnt - 1) << endl;

    return 0;
}