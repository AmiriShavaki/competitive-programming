#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> ans; 
    int i = 0;
    while(n) {
        if (n & 1) {
            ans.push_back(i);
        }
        n >>= 1;
        i++;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}