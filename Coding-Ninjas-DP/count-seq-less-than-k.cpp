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
// recursive
int countSubs(ll *A, ll n, ll k, ll mul, ll numEle) {
	if (n == 0) {
		if (numEle > 0 && mul <= k) {
			return 1;
		} else {
			return 0;
		}
	}
	int o1 = countSubs(A + 1, n - 1, k, mul, numEle);
	int o2 = countSubs(A + 1, n - 1, k, mul * A[0], numEle + 1);
	return o1 + o2;
}

void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int k ;
	cin >> k;

	ll count = 0;
	int result = countSubs(A, n, k, 1, 0);  // mul and numEle
	cout << result << endl;
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