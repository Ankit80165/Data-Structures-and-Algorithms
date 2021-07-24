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
bool isPossible(ll *A, ll n, ll h, int m) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] >= h) {
			sum += (A[i] - h);
		}
	}
	if (sum >= m) {
		return true;
	}
	return false;
}
void solve() {
	//code goes here
	ll n, m;
	cin >> n >> m;
	ll A[n];
	int maxEle = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] > maxEle) {
			maxEle = A[i];
		}
	}
	ll low = 0, high = maxEle;
	ll ans = -1;
	// cout << low << " " << high << endl;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (isPossible(A, n, mid, m)) {
			// cout << "mid = " << mid << endl;
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
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