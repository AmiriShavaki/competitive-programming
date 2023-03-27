#include <bits/stdc++.h>
using namespace std;

#define N 20

string table[N];
const int xdir[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ydir[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n;

bool check(int i, int j) {
    for (int x = 0; x < 8; x++) {
        int new_i = i + ydir[x];
        int new_j = j + xdir[x];
        if (new_i >= 0 && new_i <= n - 1 && new_j >= 0 && new_j <= n - 1 && table[new_i][new_j] == 'A') {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> table[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] != '#' && !check(i, j)) {
                table[i][j] = 'A';
            }
        }
    }
    for (int i = 0; i < n; i++) cout << table[i] << endl;
    return 0;
}