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
ll modMul(ll a, ll b) {
	return ((a % mod) * (b % mod)) % mod;
}
ll modSum(ll a, ll b) {
	return ((a % mod) + (b % mod)) % mod;
}
pair<ll, ll> calculateExp(pair<ll, ll> p1, pair<ll, ll> p2, char op) {
	if (op == '^') {
		ll tCase = modSum(modMul(p1.first , p2.second) , modMul(p1.second , p2.first)) ;
		ll fCase = modSum(modMul(p1.first , p2.first) , modMul(p1.second , p2.second));
		return {tCase, fCase};
	}
	else if (op == '|') {
		ll tCase = (modMul(p1.first , p2.first) % mod + modMul(p1.first , p2.second) % mod + modMul(p1.second , p2.first) % mod) % mod;
		ll fCase = modMul(p1.second , p2.second);
		return {tCase, fCase};
	}
	else if (op == '&') {
		ll tCase = modMul(p1.first , p2.first);
		ll fCase = (modMul(p1.second , p2.second) % mod + modMul(p1.first , p2.second) % mod + modMul(p1.second , p2.first) % mod) % mod;
		return {tCase, fCase};
	}
}
int evaluateExp(string & exp) {
	// Write your code here.
	ll n = exp.size();
	ll count = 0;
	for (ll i = 0; i < n; i++) {
		if (exp[i] == 'F' || exp[i] == 'T') count++;
	}

	vector<vector<pair<ll, ll>>> dp;
//     fill dp with zer initially
	for (ll i = 0; i < count; i++) {
		vector<pair<ll, ll>> temp;
		for (ll j = 0; j < count; j++) {
			temp.push_back({0, 0});
		}
		dp.push_back(temp);
	}
//     calculation goes here
//     pair.first = true
//     pair.second = false
	for (ll i = count - 1; i >= 0; i--) {
		for (ll j = 0; j < count; j++) {
			if (i > j) continue;
			else if (i == j) {
				if (exp[2 * i] == 'T') {
					dp[i][j] = {1, 0};
				} else if (exp[2 * i] == 'F') {
					dp[i][j] = {0, 1};
				}
			}
			else {
				// this is the most complicated part...try to visualize
				for (ll k = i; k < j; k++) {
					pair<ll, ll>p1, p2;
					p1 = dp[i][k];
					p2 = dp[k + 1][j];
					char op = exp[2 * k + 1];
					pair<ll, ll> res = calculateExp(p1, p2, op);
					dp[i][j].first = ((dp[i][j].first % mod) + (res.first % mod)) % mod;
					dp[i][j].second = ((dp[i][j].second % mod) + (res.second % mod)) % mod;
				}
			}
		}
	}
	ll ans = dp[0][count - 1].first;
	return ans;
}
void solve() {
	//code goes here
	string s;
	cin >> s;
	int ans = evaluateExp(s);
	cout << ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
