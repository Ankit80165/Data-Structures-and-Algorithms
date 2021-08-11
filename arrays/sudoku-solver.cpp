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
bool isSafe(vector<vector<int>> grid, int row, int col, int val) {
	int n = grid.size();
	// check for row
	for (int i = 0; i < n; i++) {
		if (grid[row][i] == val) {
			return false;
		}
	}
	// check for column
	for (int i = 0; i < n; i++) {
		if (grid[i][col] == val) {
			return false;
		}
	}
	// check for submatrix
	int sRow = (row / 3);
	sRow = sRow * 3;
	int sCol = (col / 3);
	sCol = sCol * 3;


	for (int i = sRow; i < sRow + 3; i++) {
		for (int j = sCol; j < sCol + 3; j++) {
			if (grid[i][j] == val) {
				return false;
			}
		}
	}

	return true;
}
bool solveSudoku(vector<vector<int>> &grid) {
	int n = grid.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				for (int val = 1; val <= 9; val++) {
					if (isSafe(grid, i, j, val)) {
						grid[i][j] = val;
						if (solveSudoku(grid)) {
							return true;
						} else {
							// backtrack
							grid[i][j] = 0;
						}
					}
				}

				return false;
			}
		}
	}

	return true;
}
void printGrid(vector<vector<int>> &grid) {
	int n = grid.size();
	for (int i = 0; i < n; ++i) {
		/* code */
		for (int j = 0; j < n; ++j) {
			/* code */
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}
void solve() {
	//code goes here
	int n = 9;
	vector<vector<int>> grid;
	for (int i = 0; i < 9; i++) {
		vector<int> row;
		for (int j = 0; j < 9; j++) {
			int value;
			cin >> value;
			row.push_back(value);
		}
		grid.push_back(row);
	}

	solveSudoku(grid);
	printGrid(grid);
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