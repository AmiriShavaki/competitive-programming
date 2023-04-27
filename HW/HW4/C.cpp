#include <bits/stdc++.h>

using namespace std;

#define N 1000006

int a[N];

int main() {
    int n; cin >> n;
    vector <int> cur;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (cur.size() == 0 || cur.back() < a[i]) {
            cur.push_back(a[i]);
        } else if (cur.size()) {
            vector <int>::iterator it = lower_bound(cur.begin(), cur.end(), a[i]);
            *it = a[i];
        }
    }
    cout << cur.size();
}