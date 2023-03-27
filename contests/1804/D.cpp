#include <bits/stdc++.h>
using namespace std;

int n, m;
int cur_mi, cur_ma;
string flr;

void get_mi_ma() {
    int oo = 0, o = flr[m - 1] == '1';
    for (int i = 0; i < m - 1; i++) {
        o += flr[i] == '1';
        if (flr[i] == flr[i + 1] && flr[i] == '1') {
            oo++;
            i++;
            if (i < m - 1)
                o += flr[i] == '1';
        }
    }
    oo = min(oo, m / 4);
    cur_mi = o - oo;
    int not_oo = 0;
    for (int i = 0; i < m - 1; i++) {
        if (!(flr[i] == flr[i + 1] && flr[i] == '1')) {
            not_oo++;
            i++;
        }
    }    
    cur_ma = o - max(0, m / 4 - not_oo);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    long long mi = 0, ma = 0;
    for (int i = 0; i < n; i++) {
        cin >> flr;
        get_mi_ma();
        mi += cur_mi;
        ma += cur_ma;
        //cout << "DEBUG " << cur_ma << endl;
    }
    cout << mi << ' ' << ma;
    return 0;
}