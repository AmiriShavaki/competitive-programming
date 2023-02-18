#include <bits/stdc++.h>
 
using namespace std;

void solve(int n) {
	if (n % 2) {
		cout << "-1";
	} else {
		cout << "1 " << n / 2;
	}
	cout << '\n';
}

int main() {

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
    	int n;
    	cin >> n;
    	solve(n);
	}

    return 0;
}