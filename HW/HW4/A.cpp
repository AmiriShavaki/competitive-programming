#include <bits/stdc++.h>

using namespace std;

#define N 100005 

int pref_lower[N], suf_upper[N];

inline int is_upp(char c) {
    return c >= 'A' && c <= 'Z';
}

inline int is_low(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    string s; cin >> s;
    pref_lower[0] = is_low(s[0]);
    for (int i = 1; i < s.size(); i++) {
        pref_lower[i] = pref_lower[i - 1] + is_low(s[i]);
    }
    suf_upper[s.size() - 1] = 0;
    for (int i = s.size() - 2; i >= 0; i--) {
        suf_upper[i] = suf_upper[i + 1] + is_upp(s[i + 1]);
    }

    int ans = N;
    for (int i = 0; i < s.size(); i++) {
        ans = min(ans, suf_upper[i] + pref_lower[i]);
    }
    cout << (pref_lower[s.size() - 1] == s.size() ? 0 : ans);
}