#include <bits/stdc++.h>
using namespace std;

#define N 100005

char ans[N];

void print(int n) {
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << endl;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        sort(s.begin(), s.end());
        int i = 0;
        for (; i + 1 < n && s[i] == s[i + 1]; i += 2) {
            ans[i / 2] = s[i];
            ans[n - i / 2 - 1] = s[i];
        }
        int j = i / 2;
        bool skip = false;
        if (i < n - 2) {
            if (s[i + 1] != s[i + 2]) {
                ans[j] = s[i + 1];
                ans[n - j - 1] = s[i];
                i += 2;
                j++;
                skip = true;
            } else {
                bool flg = true;
                for (int k = i + 1; k < n - 1; k++) {
                    flg &= s[k] == s[k + 1];
                }
                if (flg) {
                    char backup = s[i];
                    for (; i < n - 1; i += 2) {
                        ans[j] = s[n - 1];
                        ans[n - j - 1] = s[n - 1];
                        j++;
                    }
                    ans[j] = backup;
                    print(n);
                    continue;
                } else {
                    ans[j] = s[i + 1];
                    ans[n - j - 1] = s[i];
                    j++;
                    i += 2;
                    skip = true;
                }
            }
        }

        if (i == n) {
            ; // do nothing :)
        } else if (i == n - 1 && !skip) {
            ans[n / 2] = s[n - 1];   
            i++;       
        } else if (i == n - 2 && !skip) { // I'm not sure if it's always for 'even' n
            ans[n / 2 - 1] = s[n - 1];
            ans[n / 2] = s[n - 2];
            i += 2;
        }

        for (; i < n; i++) {
            ans[j++] = s[i];
        }
        print(n);

    }
    return 0;
}