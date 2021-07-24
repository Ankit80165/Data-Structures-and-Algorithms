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
int longestPalinDromicSubsDP(string s) {
	int n = s.size();
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			// row -> reverse string
			// col -> actual string
			char a = s[n - i];
			char b = s[j - 1];
			if (a == b) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][n];
}
int longestPalinDromicSubs(string s, int low, int high) {
	if (low > high) {
		return 0;
	}
	if (low == high) {
		return 1;
	}
	if (s[low] == s[high]) {
		return 2 + longestPalinDromicSubs(s, low + 1, high - 1);
	} else {
		int o1 = longestPalinDromicSubs(s, low + 1, high);
		int o2 = longestPalinDromicSubs(s, low, high - 1);
		return max(o1, o2);
	}
}
void solve() {
	//code goes here
	string s;
	cin >> s;
	int len = longestPalinDromicSubsDP(s);
	cout << len << endl;
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