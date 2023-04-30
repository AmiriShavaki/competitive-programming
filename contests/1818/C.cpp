#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define int long long

int a[N], grp[N];
bool is_first[N], is_last[N];
vector <int> grp_lens;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    is_first[0] = true;
    is_last[0] = true;
    grp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            if (a[i-1] < a[i]) {
                if (is_first[i-1]) grp_lens.push_back(1);
                else grp_lens.push_back(2);
                is_first[i] = true;
                is_last[i] = true;
                grp[i] = grp[i-1] + 1;
            } else {
                is_last[i - 1] = false;
                is_last[i] = true;
                grp[i] = grp[i-1];
            }
        }
    }
    grp_lens.push_back(1 + !is_first[n-1]);

    vector <int> psum(grp_lens.size(), 0);
    for (int i = 0; i < grp_lens.size(); i++) {
        if (i) psum[i] = psum[i - 1];
        psum[i] += grp_lens[i];
    }

    // for (int i = 0; i < n; i++) {
    //     cout << grp[i] << " \n"[i==n-1];
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << is_first[i] << " \n"[i==n-1];
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << is_last[i] << " \n"[i==n-1];
    // }    
    // for (int& i: grp_lens) {
    //     cout << i << " ";
    // } cout << endl;
    // for (int& i: psum) {
    //     cout << i << " ";
    // } cout << endl;

    for (int i = 0; i < q; i++) {
        int l, r; 
        cin >> l >> r; 
        l--; r--;

        if (r - l <= 1) cout << r - l + 1 << endl;
        else if (grp[r] == grp[l]) cout << 2 << endl;
        else cout << psum[grp[r] - 1] - psum[grp[l]] + 2 + !is_first[r] + !is_last[l] << endl;
    }

    return 0;
}