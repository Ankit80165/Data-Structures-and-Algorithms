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
void multiply(vector<vector<int>> &F, vector<vector<int>> &M) {
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}
void power(vector<vector<int>> &vec, int n) {
	if (n == 0 || n == 1) {
		return;
	}
	vector<vector<int>> v = {{1, 1}, {1, 0}};
	power(vec, n / 2);
	multiply(vec, vec);
	if (n % 2 == 1) {
		multiply(vec, v);
	}
}
int fibonacci(int n) {
	if (n == 0) {
		return 1;
	}
	vector<vector<int>> vec = {{1, 1}, {1, 0}};
	power(vec, n - 1);
	return vec[0][0];
}

void solve() {
	//code goes here
	int n;
	cin >> n;
	ll ans = fibonacci(n);
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