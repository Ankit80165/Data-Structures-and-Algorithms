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
bool isValid(int r, int c, int n) {
	if (r < 0 || r >= n || c < 0 || c >= n) {
		return false;
	}
	return true;
}
void allPaths(vector<vector<int>> m,
              int n,
              int row,
              int col,
              string &curr,
              vector<string> &ans,
              vector<vector<bool>> &visited)
{
	if (row < 0 || row >= n || col < 0 || col >= n || visited[row][col] == true || m[row][col] == 0) {
		return;
	}
	if (row == n - 1 && col == n - 1) {
		ans.push_back(curr);
		return;
	}
	visited[row][col] = true;
	// right
	if (isValid(row, col + 1, n) && m[row][col + 1] == 1) {
		curr.push_back('R');
		allPaths(m, n, row, col + 1, curr, ans, visited);
		curr.pop_back();
	}


	// down
	if (isValid(row + 1, col, n) && m[row + 1][col] == 1) {
		curr.push_back('D');
		allPaths(m, n, row + 1, col, curr, ans, visited);
		curr.pop_back();
	}


	// left
	if (isValid(row, col - 1, n) && m[row][col - 1] == 1) {
		curr.push_back('L');
		allPaths(m, n, row, col - 1, curr, ans, visited);
		curr.pop_back();
	}


	// up
	if (isValid(row - 1, col, n) && m[row - 1][col] == 1) {
		curr.push_back('U');
		allPaths(m, n, row - 1, col, curr, ans, visited);
		curr.pop_back();
	}
	visited[row][col] = false;
}
void solve() {
	//code goes here
	vector<vector<int>> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		m.push_back(temp);
	}
	string curr = "";
	vector<string> ans;
	if (ans.size() == 0) {
		return;
	}
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	allPaths(m, n, 0, 0, curr, ans, visited);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
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