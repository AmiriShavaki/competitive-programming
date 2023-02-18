#include <bits/stdc++.h>

using namespace std;
 
//https://codeforces.com/blog/entry/112149 
template<int MOD>
struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(long long p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<998244353> mint;

const int N = 1000006;

mint dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		
		int k = 0;
		for (int i = 0; i < n; i++) {
			k += a[i] != b[i];
		}
		
		dp[n] = 1;
		for (int i = n - 1; i > 0; i--) {
			dp[i] = (mint) n / i + ( ((mint)n - i) / i) * dp[i + 1];
		}
		
		mint ans = 0;
		for (int i = 1; i <= k; i++) {
			ans += dp[i];
		}
		
		cout << ans << endl;
	}
	return 0;
}