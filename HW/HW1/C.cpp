#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int n, k, x;
    cin >> n >> k >> x;
    int final_channel = (k + x - 1) % n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i == final_channel)
            cout << s << endl;
    }
    
    return 0;
}