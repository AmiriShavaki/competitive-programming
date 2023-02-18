#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		bool flg1 = false;
		bool flg2 = false;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
			if (i > 0) {
				if (a[i] == 1 && a[i - 1] == -1 || a[i] == -1 && a[i - 1] == 1) flg1 = true;
				if (a[i] == -1 && a[i - 1] == -1) flg2 = true;
			}
		}
		if (flg2) {
			sum += 4;
		} else if (flg1) {
			sum = sum;
		} else {
			sum -= 4;
		}
		printf("%d\n", sum);
	}
	return 0;
}