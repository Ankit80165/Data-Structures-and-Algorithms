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
int lcs(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	int dp[2][m + 1];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m + 1; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 1; j < m + 1; j++) {
				if (s1[i] == s2[j - 1]) {
					dp[1][j] = 1 + dp[0][j - 1];
				} else {
					dp[1][j] = max(dp[1][j - 1], dp[0][j]);
				}
			}
		} else {
			for (int j = 1; j < m + 1; j++) {
				if (s1[i] == s2[j - 1]) {
					dp[0][j] = 1 + dp[1][j - 1];
				} else {
					dp[0][j] = max(dp[0][j - 1], dp[1][j]);
				}
			}
		}
	}
	if ((n - 1) % 2 == 1) {
		return dp[0][m];
	} else {
		return dp[1][m];
	}
}
void solve() {
	//code goes here
	string s1, s2;
	cin >> s1 >> s2;
	ll ans = lcs(s1, s2);
	cout << ans << endl;
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