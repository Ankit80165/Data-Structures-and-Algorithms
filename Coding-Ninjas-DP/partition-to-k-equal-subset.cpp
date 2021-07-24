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
bool isPossible(ll *A, int n, int k, std::vector<ll> &v) {
	if (n <= 0) {
		int f = v[0];
		for (int i = 1; i < v.size(); i++) {
			if (v[i] != f) {
				return false;
			}
		}
		if (f == 0) {
			return false;
		}
		return true;
	}
	int curr = A[0];
	bool res = false;
	for (int i = 0; i < k; i++) {
		v[i] += curr;
		res = res || isPossible(A + 1, n - 1, k, v);
		v[i] -= curr;
	}
	return res;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int k;
	cin >> k;
	std::vector<ll> v(k, 0);
	if (isPossible(A, n, k, v)) {
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

	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}