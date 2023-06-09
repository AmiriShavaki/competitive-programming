#include<bits/stdc++.h>

using namespace std;

#define N 100005

int a[N];
map <int, int> cnt;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int single = 0;
    for (map <int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        single += it -> second == 1;
        // cout << it -> first << ' ' << it -> second << '\n';
    }
    cout << single / 2 + single % 2 + (cnt.size() - single);
    return 0;
}