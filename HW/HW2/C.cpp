#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> k(n);
    vector < pair<int, int> > indices;
    vector < vector < int > > b(n);
    vector < vector < int > > label(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        b[i].resize(k[i]);
        label[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) {
            cin >> b[i][j];
            indices.push_back(make_pair(i, j));
        }
    }

    sort(indices.begin(), indices.end(), 
        [&](pair <int, int> ind1, pair <int, int> ind2) -> bool {
            return b[ind1.first][ind1.second] < b[ind2.first][ind2.second];
        }
    );

    label[indices[0].first][indices[0].second] = 0;
    for (int i = 1; i < indices.size(); i++) { 
        int x = indices[i].first, y = indices[i].second;
        int prev_x = indices[i - 1].first, prev_y = indices[i - 1].second;
        label[x][y] = label[prev_x][prev_y] + (b[prev_x][prev_y] != b[x][y]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for (int j = 1; j < k[i]; j++) {
            if (label[i][j] != label[i][j - 1] && label[i][j] - label[i][j - 1] != 1) {
                ans++;
            }
        }
    }
    cout << ans << ' ' << n + ans - 1 << endl;

    return 0;
}