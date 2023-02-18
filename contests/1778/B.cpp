#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N], p[N], pos[N];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m, d;
		scanf("%d%d%d", &n, &m, &d);
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			pos[p[i]] = i + 1;
		}
		bool flg = false;
		int min_dis = N;
		int max_dis = -1;
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
			if (i > 0) {
				if (pos[a[i - 1]] > pos[a[i]]) flg = true;
				min_dis = min(min_dis, pos[a[i]] - pos[a[i - 1]]);
				max_dis = max(max_dis, pos[a[i]] - pos[a[i - 1]]);
			}
		}		
		if (flg || max_dis > d) puts("0");
		else {
			int ans1 = min_dis;
			int ans2 = (d < n-1 ? 1 + d - max_dis : N);
			//printf("Debug %d %d\n", ans1, ans2);
			printf("%d\n", min(ans1, ans2));
		}
	}
	return 0;
}