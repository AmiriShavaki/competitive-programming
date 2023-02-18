#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char a[N], b[N];

inline long long substr_cnt(long long n) {
	return n*(n+1)/2;
}

long long evalute(map <char, bool> &mp, int n) {
	long long sum = 0;
	long long longest = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] || mp.find(a[i]) != mp.end()) {
			longest++;
		} else {
			sum += substr_cnt(longest);
			longest = 0;
		}
	}
	if (longest) {
		sum += substr_cnt(longest);
	}
	return sum;
}

long long go(int max_chic, string chose, int n, int i, string& full_chars, int nn) {
	if ((int)chose.size() == max_chic) {
		map <char, bool> t_mp;
		for (int j = 0; j < chose.size(); j++) {
			t_mp[chose[j]] = true;
		}
		return evalute(t_mp, nn);
	}
	if (i == n) {
		return 0;
	}
	else {
		i++;
		long long ans1 = go(max_chic, chose, n, i, full_chars, nn);
		chose += full_chars[i-1];
		long long ans2 = go(max_chic, chose, n, i, full_chars, nn);
		return max(ans1, ans2);
	}
}

void solve(int choice_cnt, int n, string& fullchars) {
	printf("%lld\n", go(choice_cnt, "", (int)fullchars.size(), 0, fullchars, n));
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d%s%s", &n, &k, a, b);
		
		map <char, bool> mp;
		
		string fullchars;
		
		for (int i = 0; i < n; i++) {
			if (mp.find(a[i]) == mp.end()) {	
				mp[a[i]] = false;
				fullchars += a[i];
			}
		}
		
		int choice_cnt = min(k, (int)mp.size());
		solve(choice_cnt, n, fullchars);
	}
	return 0;
}