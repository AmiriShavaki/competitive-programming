#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define int long long

int b[N];

int maxvec(vector <int>& vec) {
    int ma = vec[0];
    for (int i = 1; i < 3; i++) ma = max(ma, vec[i]);
    return ma;
}

int min2vec(vector <int>& vec) {
    int x[3] = {1, 0, 0};
    int y[3] = {2, 2, 1};
    for (int i = 0; i < 3; i++) {
        if (vec[i] <= vec[x[i]] && vec[i] >= vec[y[i]]) {
            return vec[i];
        }
        if (vec[i] >= vec[x[i]] && vec[i] <= vec[y[i]]) {
            return vec[i];
        }
    }
}

int minvec(vector <int>& vec) {
    int mi = vec[0];
    for (int i = 1; i < 3; i++) mi = min(mi, vec[i]);
    return mi;
}

int dif(int& new_num, int& new_ind, vector <int>& indices, vector <int>& maxes) {
    int old_ans = maxes[0] + maxes[1] + maxes[2];
    int ma = -1, best_candid;

    int l = minvec(indices);
    int r = maxvec(indices);
    int l2 = min2vec(indices);

    for (int candid = 0; candid < 3; candid++) {
        int new_ans = new_num; for (int i = 0; i < 3; i++) if (candid != i) new_ans += maxes[i];
        if ( (new_ind - l2) + new_ans > ma) {
            ma = (new_ind - l2) + new_ans;
            best_candid = candid;
        }
    }

    if (ma > old_ans + (r - l)) {
        indices.erase(indices.find(l));
        maxes.erase(maxes.find());
    }

    return ma;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> b[i];

        vector <int> indices; for (int i = 0; i < 3; i++) indices.push_back(i);
        sort(indices.begin(), indices.end(), 
            [&](int ind1, int ind2) -> bool {
                return b[ind1] > b[ind2];
            }
        );

        vector <int> maxes; for (int i = 0; i < 3; i++) maxes.push_back(b[indices[i]]);
        // cout << maxes[0] << ' ' << maxes[1] << ' ' << maxes[2] << endl;

        // cout << dif(10, 5, indices, maxes);
        int ans = maxes[0] + maxes[1] + maxes[2] - 2;
        for (int i = 4; i < n; i++) {
            int ma = dif(b[i], i, indices, maxes);
            ans = max(ma, ans);
        }
        cout << ans << endl;
    }
    return 0;
}