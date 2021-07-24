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
// recursion version
int getMaxProfit(int n, int k, vector<int>time, vector<int> profit, int curr) {
	// cout << "curr = " << curr << endl;
	if (curr >= k) {
		return 0;
	}
	if (time[curr] > n) {
		return getMaxProfit(n, k, time, profit, curr + 1);
	} else {
		int o1 = getMaxProfit(n, k, time, profit, curr + 1);
		int o2 = profit[curr] + getMaxProfit(n - time[curr], k, time, profit, curr + 1);
		return max(o1, o2);
	}
}
// iterative dynamic programming
int getMaxProfit(int n, int k, vector<int> time, vector<int> profit) {
	int dp[n + 1][k + 1];
	// fill first row
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if (time[j - 1] > i) {
				dp[i][j] = dp[i][j - 1];
			} else {
				dp[i][j] = max(profit[j - 1] + dp[i - time[j - 1]][j - 1] , dp[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return dp[n][k];
}
void solve() {
	//code goes here
	ll n, k;
	cin >> k >> n;
	// cout << n << k << endl;
	vector<int> time, profit;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		time.push_back(a);
	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		// cout << "bittu1" << endl;
		profit.push_back(a);
	}
	// cout << "bittu" << endl;
	int res = getMaxProfit(n, k, time, profit);
	cout << "res = " << res << endl;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}