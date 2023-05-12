#include <bits/stdc++.h>
using namespace std;

map<pair <string, string>, double> mp;
map<string, int> bedeh_cnt, talab_cnt;
map<string, double> bal;
set < pair<double, string> > bal_api1, bal_api2;

inline bool eq_z(double x) {
    return x < 0.001 && x > -0.001;
} 
inline bool pos(double x) {
    return x > 0.001;
}
inline bool neg(double x) {
    return x < -0.001;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    for (int _ = 0; _ < q; _++) {
        int op; cin >> op;
        if (op == 1) {
            string s1, s2; double x; cin >> s1 >> s2 >> x;
            double old = mp[make_pair(s1, s2)];
            mp[make_pair(s1, s2)] += x;

            if (bal_api1.find(make_pair(-bal[s1], s1)) != bal_api1.end())
            bal_api1.erase(bal_api1.find(make_pair(-bal[s1], s1))); 
            if (bal_api1.find(make_pair(-bal[s2], s2)) != bal_api1.end())
            bal_api1.erase(bal_api1.find(make_pair(-bal[s2], s2)));
            if (bal_api2.find(make_pair(bal[s1], s1)) != bal_api2.end())
            bal_api2.erase(bal_api2.find(make_pair(bal[s1], s1))); 
            if (bal_api2.find(make_pair(bal[s2], s2)) != bal_api2.end())
            bal_api2.erase(bal_api2.find(make_pair(bal[s2], s2)));
            double bals1 = bal[s1], bals2 = bal[s2];
            if (bal.find(s1) != bal.end())
            bal.erase(bal.find(s1)); 
            if (bal.find(s2) != bal.end())
            bal.erase(bal.find(s2));
            bal[s1] = bals1 - x; bal[s2] = bals2 + x;
            // bal[s1] -= x;
            // bal[s2] += x;
            bal_api1.insert(make_pair(-bal[s1], s1)); 
            bal_api1.insert(make_pair(-bal[s2], s2));
            bal_api2.insert(make_pair(bal[s1], s1)); 
            bal_api2.insert(make_pair(bal[s2], s2));

            if (eq_z(old)) {
                if (pos(mp[make_pair(s1, s2)])){
                talab_cnt[s1]++; bedeh_cnt[s2]++;}
                if (neg(mp[make_pair(s1, s2)])){
                talab_cnt[s2]++; bedeh_cnt[s1]++;}
            } else if (neg(old)) {
                if ( eq_z(mp[make_pair(s1, s2)]) ) {
                    talab_cnt[s2]--; bedeh_cnt[s1]--;
                } else if ( pos(mp[make_pair(s1, s2)]) ) {
                    talab_cnt[s2]--; bedeh_cnt[s1]--;
                    talab_cnt[s1]++; bedeh_cnt[s2]++;
                }
            } else if (pos(old)) {
                if ( eq_z(mp[make_pair(s1, s2)]) ) {
                    talab_cnt[s1]--; bedeh_cnt[s2]--;
                } else if ( neg(mp[make_pair(s1, s2)]) ) {
                    talab_cnt[s2]++; bedeh_cnt[s1]++;
                    talab_cnt[s1]--; bedeh_cnt[s2]--;
                }
            }
            mp[make_pair(s2, s1)] += -x;
        } else if (op == 2) {
            string res = bal_api1.begin()->second;
            if ( pos(bal[res]) ) cout << res << endl;
            else cout << -1 << endl;
        } else if (op == 3) {
            string res = bal_api2.begin()->second;
            if ( neg(bal[res]) ) cout << res << endl;
            else cout << -1 << endl;            
        } else if (op == 4) {
            string s; cin >> s;
            cout << bedeh_cnt[s] << endl;
        } else if (op == 5) {
            string s; cin >> s;
            cout << talab_cnt[s] << endl;            
        } else if (op == 6) {
            string s1, s2; cin >> s1 >> s2;
            if (eq_z(mp[make_pair(s2, s1)])) cout << "0.00\n";
            else
            cout << fixed << setprecision(2) << mp[make_pair(s2, s1)] << endl;
        }
    }
    return 0;
}