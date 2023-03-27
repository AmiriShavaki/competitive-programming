#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r]) {l++; r--;}
        if (l >= r) {
            cout << "Yes\n";
            continue;
        } else {
            while (l < r && s[l] != s[r]) {l++; r--;}
            if (l >= r) {
                cout << "Yes\n";
                continue;                
            }
            while (l < r && s[l] == s[r]) {l++; r--;}
            if (l >= r) {
                cout << "Yes\n";
                continue;                
            }         
            cout << "No\n";   
        }
    }
    return 0;
}