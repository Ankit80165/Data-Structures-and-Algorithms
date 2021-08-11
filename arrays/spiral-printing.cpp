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
void spiralPrint(int rowStart,
                 int rowEnd,
                 int colStart,
                 int colEnd,
                 vector<vector<int>> grid,
                 vector<int> &res) {
	// cout << rowStart << " " << rowEnd << endl;
	// cout << colStart << " " << colEnd << endl;
	if (rowStart > rowEnd) {
		return;
	}
	if (colStart > colEnd) {
		return;
	}
	if (rowEnd - rowStart == 0) {
		for (int i = colStart; i <= colEnd; i++) {
			res.push_back(grid[rowStart][i]);
		}
		return;
	}
	if (colEnd - colStart == 0) {
		for (int i = rowStart; i <= rowEnd; i++) {
			res.push_back(grid[i][colEnd]);
		}
		return;
	}
	// top part
	for (int i = colStart; i <= colEnd; i++) {
		res.push_back(grid[rowStart][i]);
	}
	// last col
	for (int i = rowStart + 1; i <= rowEnd; i++) {
		res.push_back(grid[i][colEnd]);
	}
	// last row
	for (int i = colEnd - 1; i >= colStart; i--) {
		res.push_back(grid[rowEnd][i]);
	}
	// first col
	for (int i = rowEnd - 1; i >= rowStart + 1; i--) {
		res.push_back(grid[i][colStart]);
	}
	spiralPrint(rowStart + 1, rowEnd - 1, colStart + 1, colEnd - 1, grid, res);
}
void print(vector<int> res) {
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
void solve() {
	//code goes here
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	vector<int> result;
	spiralPrint(0, n - 1, 0, m - 1, grid, result);
	print(result);
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