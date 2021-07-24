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
int noOfWays(int n, int k) {
	if (n == 1) {
		return k;
	}
	int prev_fcase = k;
	int prev_scase = ((k % mod) * ((k - 1) % mod)) % mod;
	int prev_total = (prev_fcase % mod + prev_scase % mod) % mod;

	for (int i = 3; i <= n; i++) {
		int curr_fcase = prev_scase;
		int curr_scase = ((prev_total % mod) * ((k - 1) % mod)) % mod;
		int curr_total = (curr_fcase % mod + curr_scase % mod) % mod;

		prev_fcase = curr_fcase;
		prev_scase = curr_scase;
		prev_total = curr_total;
	}
	return prev_total;
}
void solve() {
	//code goes here
	int n, k;
	cin >> n >> k;
	int totalWays = noOfWays(n, k);
	cout << totalWays << endl;
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