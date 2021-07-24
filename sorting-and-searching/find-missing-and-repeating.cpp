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
int *findRes(ll *A, ll n) {
	// code here
	for (int i = 0; i < n; i++) {
		while (A[A[i] - 1] != A[i]) {
			swap(A[i], A[A[i] - 1]);
		}
	}
	int *res = new int(2);

	for (int i = 0; i < n; i++) {
		if (A[i] != i + 1) {
			res[0] = A[i];
			res[1] = i + 1;
			break;
		}
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
	int *res = findRes(A, n);
	for (int i = 0; i < 2; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
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