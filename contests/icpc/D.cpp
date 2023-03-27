#include <bits/stdc++.h>
using namespace std;

const int dirx[] = {1, 0, -1, 0};
const int diry[] = {0, -1, 0, 1};
int mat[2003][2003];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int s, d;
    cin >> s >> d;
    int s_x, s_y, d_x, d_y;
    int x = 0, y = n - 1, cnt = 1;
    int dir = 0;
    do {
        mat[y][x] = cnt;
        if (cnt == s) {
            s_x = x; s_y = y;
        }
        if (cnt == d) {
            d_x = x; d_y = y;
        }
        if (x + dirx[dir] < 0 || y + diry[dir] < 0) dir = (dir + 1) % 4;
        else if (x + dirx[dir] >= n || y + diry[dir] >= n) dir = (dir + 1) % 4;
        else if (mat[y + diry[dir]][x + dirx[dir]]) dir = (dir + 1) % 4;
        x += dirx[dir];
        y += diry[dir];
        //cout << x << ' ' << y << endl;
    } while(cnt++ != n * n);
    if (s_x != d_x)
        cout << abs(s_x - d_x) << (s_x < d_x ? " R" : " L") << endl;
    if (s_y != d_y)
        cout << abs(s_y - d_y) << (s_y > d_y ? " U" : " D") << endl;
    //cout << s_x << ' ' << s_y << ' ' << d_x << ' ' << d_y << endl;
    return 0;
}