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
bool isSafe(int **edges, int n, int c, vector<int> color, int node) {
	for (int i = 0; i < n; i++) {
		if (edges[node][i] && color[i] == c) {
			return false;
		}
	}
	return true;
}
bool isPossibleToColor(int **edges, int n, int m, vector<int> &color, int sv) {
	if (sv == n) {
		return true;
	}
	for (int i = 1; i <= m; i++) {
		if (isSafe(edges, n, i, color, sv)) {
			color[sv] = i;
			if (isPossibleToColor(edges, n, m, color, sv + 1)) {
				return true;
			}
			color[sv] = -1;
		}
	}
	return false;
}
void solve() {
	//code goes here
	int n, m, e;
	cin >> n >> m >> e;
	int **edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
	// taking graph input
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f - 1][s - 1] = 1;
		edges[s - 1][f - 1] = 1;
	}
	vector<int> color(n, -1);
	if (isPossibleToColor(edges, n, m, color, 0)) {
		cout << "possible" << endl;
	} else {
		cout << "Not possible" << endl;
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