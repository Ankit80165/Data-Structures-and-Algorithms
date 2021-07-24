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
int countWays(int d, int f, int s) {
	if (d == 0 && s == 0) {
		return 1;
	}
	if (d <= 0) {
		return 0;
	}

	int sum = 0;
	for (int i = 1; i <= f; i++) {
		int count = countWays(d - 1, f, s - i);
		// cout << count << endl;
		sum += count;
	}
	return sum;
}
int countWaysDP(int d, int f, int s) {
	int dp[s + 1][d + 1];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 1; i < s + 1; i++) {
		for (int j = 1; j < d + 1; j++) {
			int count = 0;
			for (int k = 1; k <= f; k++) {
				int remain = i - k;
				if (remain >= 0) {
					count = ((count % mod) + (dp[remain][j - 1] % mod)) % mod;
				}
			}
			dp[i][j] = count;
		}
	}

	return dp[s][d];
}
void solve() {
	//code goes here
	int d, f, s;
	cin >> d >> f >> s;
	ll ans = countWaysDP(d, f, s);
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