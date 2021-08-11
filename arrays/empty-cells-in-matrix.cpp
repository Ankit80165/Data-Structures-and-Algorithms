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
void solve() {
	//code goes here
	int n, k;
	cin >> n >> k;
	int distinctRow = 0;
	int distinctCol = 0;
	int total = n * n;
	int rem = n * n;
	unordered_map<int, bool> row, col;
	for (int i = 1; i <= k; i++) {
		int r, c;
		cin >> r >> c;
		if (row.find(r) != row.end() && col.find(c) != col.end()) {
			cout << rem << " ";
		}
		else if (row.find(r) != row.end()) {
			distinctCol++;
			int empty = n - distinctRow;
			cout << rem - empty << " ";
			rem = rem - empty;
		}
		else if (col.find(c) != col.end()) {
			distinctRow++;
			int empty = n - distinctCol;
			cout << rem - empty << " ";
			rem = rem - empty;
		} else {
			int emptyRow = n - distinctCol;
			int emptyCol = n - distinctRow;
			distinctCol++;
			distinctRow++;
			int t = emptyRow + emptyCol - 1;
			cout << rem - t << " ";
			rem -= t;
		}
		row[r] = true;
		col[c] = true;
	}
	cout << endl;
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