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
bool isValid(int r, int c, int row, int col) {
	if (r < 0 || r >= row || c < 0 || c >= col) {
		return false;
	}
	return true;
}
void dfs(vector<vector<int>> grid,
         int cr,
         int cc,
         int row,
         int col,
         vector<vector<bool>> &visited)
{
	cout << "cr = " << cr << " " << "cc = " << cc << endl;
	if (cr < 0 || cr >= row || cc < 0 || cc >= col || visited[cr][cc] || grid[cr][cc] == 0) {
		return;
	}
	visited[cr][cc] = true;
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	for (int i = 0; i < 4; i++) {
		int r = cr + dr[i];
		int c = cc + dc[i];
		if (isValid(r, c, row, col) && grid[r][c] == 1) {
			dfs(grid, r, c, row, col, visited);
		}
	}

}
int numIslands(std::vector<vector<int>> grid) {
	int r = grid.size();
	int c = grid[0].size();
	vector<vector<bool>> visited(r, vector<bool>(c, false));
	int count = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == false && grid[i][j] == 1) {
				cout << i << " " << j << endl;
				dfs(grid, i, j, r, c, visited);
				cout << "----------------------" << endl;
				count++;
			}
		}
	}
	return count;
}
void solve() {
	//code goes here
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			temp.push_back(num);
		}
		grid.push_back(temp);
	}
	int total = numIslands(grid);
	cout << total << endl;
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