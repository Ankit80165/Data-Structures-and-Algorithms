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

int seg[10000];
int build(int index, int low, int high, int *A, int n) {
	cout << "Ankit" << endl;
	if (low == high) {
		seg[index] = A[low];
		return seg[index];
	}
	int mid = (low + high) / 2;
	int left = build(2 * index + 1, low, mid, A, n);
	int right = build(2 * index + 2, mid + 1, high, A, n);
	seg[index] = max(left, right);
	return seg[index];
}
int query(int index, int low, int high, int l, int r) {
	if (low >= l && high <= r) {
		return seg[index];
	}
	if (low > r || high < l) {
		return INT_MIN;
	}
	int mid = (low + high) / 2;
	int left = query(2 * index + 1, low, mid, l, r);
	int right = query(2 * index + 2, mid + 1, high, l, r);
	return max(left, right);
}
void solve() {
	//code goes here
	int n, q;
	cin >> n >> q;
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	build(0, 0, n - 1, A, n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		int result = query(0, 0, n - 1, l, r);
		cout << result << endl;
	}
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