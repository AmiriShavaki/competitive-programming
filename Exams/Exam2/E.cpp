#include<bits/stdc++.h>

using namespace std;

#define N 100005

int a[N];

int main() {
    multiset <int> sorted_from_end, sorted_from_start;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted_from_end.insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sorted_from_end.erase(sorted_from_end.find(a[i]));
        // cout << a[i] << " ";
        int dist1 = distance(sorted_from_end.begin(), sorted_from_end.lower_bound(a[i]));
        int dist2 = distance(sorted_from_start.begin(), sorted_from_start.lower_bound(a[i]));
        // cout << dist1 << " ";
        // cout << dist2 << endl;
        ans += dist1 * dist2;
        sorted_from_start.insert(a[i]);
    }
    cout << ans << endl;
}