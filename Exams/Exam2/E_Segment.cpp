#include<bits/stdc++.h>

using namespace std;

#define N 100005

int a[N];
int node[4 * N];
int del[N];
int indices[N];

void build(int l, int r, int id) {
    if (l == r) {
        node[id] = del[l];
        return;
    }
    else {
        cout << l << ' ' << r << ' ' << id << endl;
        int mid = (l + r) / 2;
        build(l, mid, id<<1);
        build(mid, r, id<<1|1);
        node[id] = node[id<<1] + node[id<<1|1];
    }
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        del[i] = 1;
        indices[i] = i;
    }
    int maxp2 = n & (n - 1) ? 2ull << __lg(n) : n;
    build(0, maxp2 - 1, 1);
    sort(indices, indices + n, 
        [&](int ind1, int ind2) -> bool {
            return a[ind1] > a[ind2];
        }
    );
    for (int i = 0; i < n; i++) {
        cout << indices[i] << " ";
    }
}