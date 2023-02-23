#include <bits/stdc++.h>
using namespace std;

void print(multiset<int> ms) {
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << "Debug " << *it << ' ';
    }
    cout << endl;
}

int f(int x) {
    int ans = 0;
    while(x) {
        ans++;
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        multiset < int > ms1, ms2;
        int n, a_i, b_i;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a_i;
            ms1.insert(a_i);
        }
        multiset<int>::iterator it;
        for (int i = 0; i < n; i++) {
            cin >> b_i;
            it = ms1.find(b_i);
            if (it == ms1.end()) {
                ms2.insert(b_i);
            } else {
                ms1.erase(it);
            }
        }
        int ans = 0;
        while (!ms1.empty()) {
            ans++;
            int mx1 = *ms1.rbegin(), mx2 = *ms2.rbegin();
            if (mx1 > mx2) {
                int f_mx1 = f(mx1);
                it = ms2.find(f_mx1);
                if (it == ms2.end()) {
                    ms1.insert(f_mx1);
                } else {
                    ms2.erase(it);
                }
                ms1.erase(--ms1.end());
            } else {
                int f_mx2 = f(mx2);
                it = ms1.find(f_mx2);
                if (it == ms1.end()) {
                    ms2.insert(f_mx2);
                } else {
                    ms1.erase(it);
                }
                ms2.erase(--ms2.end());
            }
        }
        cout << ans << endl;
    }

    return 0;
}