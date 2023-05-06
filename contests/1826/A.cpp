#include <bits/stdc++.h>
using namespace std;

#define N 102
//#define int long long

int a[N], cnt[N], sufsum[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        set <int> sorted;
        int ma = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; cnt[a[i]]++; sorted.insert(a[i]); ma = max(ma, a[i]);
        }

        if (ma == 0) {
            cout << "0\n";
            continue;
        }

        sufsum[n] = cnt[n];
        for (int i = n-1; i >= 0; i--) {
            sufsum[i] = sufsum[i + 1] + cnt[i];
        }

        int liars_cnt = 0;
        bool done = false;

        for (set<int>::reverse_iterator rit = sorted.rbegin(); rit != sorted.rend() && !done; ++rit) {
            set<int>::reverse_iterator rit2 = rit; ++rit2;
            //if (rit2 != sorted.rend()) cout << *(rit2) << endl;
            liars_cnt += cnt[*rit];
            if (rit2 != sorted.rend()) {
                if (liars_cnt < *rit && liars_cnt >= *rit2) {
                    cout << liars_cnt << endl;
                    done = true;
                }
            } else {
                if (liars_cnt < *rit) {
                    cout << liars_cnt << endl;
                    done = true;
                }
            }
        }
        if (!done) cout << "-1\n";

        for (int i = 0; i < n; i++) {
            cnt[a[i]]--;
        }
    }
    return 0;
}