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
bool isValid(int r, int c, int n, int m) {
	if (r < 0 || r >= n || c < 0 || c >= m) {
		return false;
	}
	return true;
}
void dfs(vector<vector<int>> &A,
         int r,
         int c,
         int n,
         int m,
         int col,
         int &count,
         vector<vector<char>> &blue)
{
	if (r < 0 || r >= n || c < 0 || c >= m) {
		return;
	}
	if (blue[r][c] == 'B') {
		return;
	}
	blue[r][c] = 'B';
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];
		if (isValid(rr, cc, n, m)) {
			if (A[rr][cc] >= A[r][c]) {
				dfs(A, rr, cc, n, m, col, count, blue);
			}
		}
	}
	return;
}
void dfsRed(vector<vector<int>> &A,
            int r,
            int c,
            int n,
            int m,
            int col,
            int &count,
            vector<vector<char>> &red)
{
	if (r < 0 || r >= n || c < 0 || c >= m) {
		return;
	}
	if (red[r][c] == 'R') {
		return;
	}
	red[r][c] = 'R';
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i];
		int cc = c + dc[i];
		if (isValid(rr, cc, n, m)) {
			if (A[rr][cc] >= A[r][c]) {
				dfsRed(A, rr, cc, n, m, col, count, red);
			}
		}
	}
	return;
}
void print(vector<vector<char>> vec) {
	int n = vec.size();
	int m = vec[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return;
}
int  countResult(vector<vector<char>> blue, vector<vector<char>> red) {
	int n = blue.size();
	int m = blue[0].size();
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (blue[i][j] == 'B' && red[i][j] == 'R') {
				count++;
			}
		}
	}
	return count;
}
int countWayOfWater(vector<vector<int> > &A) {
	// first traversal of blue
	int n = A.size();
	int m = A[0].size();
	int count = 0;
	vector<vector<char>> blue(n, vector<char>(m, '.'));
	vector<vector<char>> red(n, vector<char>(m, '.'));
	// blue top row
	for (int i = 0; i < m; i++) {
		if (blue[0][i] == '.') {
			dfs(A, 0, i, n, m, 1, count, blue);
		}
	}
	// blue left
	for (int i = 0; i < n; i++) {
		if (blue[i][0] == '.') {
			dfs(A, i, 0, n, m, 1, count, blue);
		}
	}


	for (int i = 0; i < m; i++) {
		if (red[n - 1][i] == '.') {
			dfsRed(A, n - 1, i, n, m, 0, count, red);
		}
	}
	for (int i = 0; i < n; i++) {
		if (red[i][m - 1] == '.') {
			dfsRed(A, i, m - 1, n, m, 0, count, red);
		}
	}
	// print(blue);
	// print(red);
	int c = countResult(blue, red);
	return c;
}

void solve() {
	//code goes here
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int count = countWayOfWater(board);
	cout << count << endl;
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