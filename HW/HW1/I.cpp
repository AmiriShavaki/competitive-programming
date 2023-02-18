#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        int a_i;
        cin >> a_i;

        for (int i = 0; i < (a_i <= 3 ? a_i : 1); i++) cout << '*';
        cout << endl;
    }

    return 0;
}