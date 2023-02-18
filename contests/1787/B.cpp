#include <bits/stdc++.h>
 
using namespace std;

void solve(int n) {
	vector <pair <int, int > > pf;
	int div = 2;
	int mul = 1;
	while (n > 1 && div * div <= n) {
		int i = 0;
		while (n % div == 0) {
			i++;
			n /= div;
		}
		if (i) {
			pf.push_back(make_pair(i, div));
			mul *= div;
		}
		div++;
	}
	
	if (n != 1) {
		pf.push_back(make_pair(1, n));
		mul *= n;
	}
	
	sort(pf.begin(), pf.end());
	
	int ans = 0;
	int last_exp = 0;
	for (int i = 0; i < pf.size(); i++) {
		ans += mul * (pf[i].first - last_exp);
		last_exp = pf[i].first;
		mul /= pf[i].second;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		solve(n);
	}
    return 0;
}