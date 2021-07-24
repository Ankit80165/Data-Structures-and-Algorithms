// best time to buy and sell stocks when
// infinite transaction are allowed
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
int maxProfit(ll *A, ll n) {
	int b = A[0], s = A[0];
	ll maxRes = 0;
	for (int i = 1; i < n; i++) {
		if (A[i] >= s) {
			s = A[i];
		} else {
			maxRes += (s - b);
			s = A[i];
			b = A[i];
		}
	}
	if (s > b) {
		maxRes += (s - b);
	}
	return maxRes;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	ll ans = maxProfit(A, n);
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