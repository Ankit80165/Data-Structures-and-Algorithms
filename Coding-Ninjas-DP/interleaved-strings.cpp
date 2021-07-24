#include<bits/stdc++.h>
#include<cstring>
#include<climits>
using namespace std;
#define add(x) accumulate(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
ll GCD(ll x, ll y) {return __gcd(x, y);}
ll LCM(ll x, ll y) {return (x * y) / __gcd(x, y);}
bool isInterleavedDP(string a, string b, string c) {
	int na = a.size();
	int nb = b.size();
	int nc = c.size();
	if (nc != na + nb) {
		return false;
	}
	bool dp[na + 1][nb + 1];
	for (int i = 0; i < na + 1; i++) {
		for (int j = 0; j < nb + 1; j++) {
			if (i == 0 && j == 0) dp[i][j] = true;
			else if (i == 0) {
				if (b[j - 1] != c[i + j - 1]) {
					dp[i][j] = false;
				} else {
					dp[i][j] = dp[i][j - 1];
				}
			}
			else if (j == 0) {
				if (a[i - 1] != c[i + j - 1]) {
					dp[i][j] = false;
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {
				char ca = a[i - 1], cb = b[j - 1], cc = c[i + j - 1];
				if (cc == ca && cc == cb) {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
				else if (cc == ca) {
					dp[i][j] = dp[i - 1][j];
				} else if (cc == cb) {
					dp[i][j] = dp[i][j - 1];
				} else {
					dp[i][j] = false;
				}
			}
		}
	}
	return dp[na][nb];
}
bool isInterleaved(string a, string b, string c) {
	int na = a.size();
	int nb = b.size();
	int nc = c.size();
	if (nc != na + nb) {
		return false;
	}
	if (na == 0) {
		if (c == b) {
			return true;
		}
		return false;
	}
	if (nb == 0) {
		if (a == c) {
			return true;
		}
		return false;
	}

	char ca = a[0], cb = b[0], cc = c[0];
	if (ca == cc && cb == cc) {
		bool f1 = isInterleaved(a.substr(1, na - 1), b, c.substr(1, nc - 1));
		bool f2 = isInterleaved(a, b.substr(1, nb - 1), c.substr(1, nc - 1));
		return f1 || f2;
	}
	else if (cc == ca) {
		return isInterleaved(a.substr(1, na - 1), b, c.substr(1, nc - 1));
	}
	else if (cc == cb) {
		return isInterleaved(a, b.substr(1, nb - 1), c.substr(1, nc - 1));
	}
	else {
		return false;
	}
}
void solve() {
	//code goes here
	string a, b, c;
	cin >> a >> b >> c;
	if (isInterleavedDP(a, b, c)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;

	solve();
	return 0;
}