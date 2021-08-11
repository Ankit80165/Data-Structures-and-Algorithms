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
bool isPossible(vector<vector<char>> board,
                string word,
                int r,
                int c,
                int n,
                int m,
                vector<vector<bool>> &visited)
{
	// cout << r << " " << c << endl;
	if (word.size() == 0) {
		return true;
	}
	if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] == true || word[0] != board[r][c]) {
		return false;
	}
	visited[r][c] = true;
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int len = word.size();
	for (int i = 0; i < 4; i++) {
		if (isPossible(board, word.substr(1, len - 1), r + dr[i], c + dc[i], n, m, visited)) {
			return true;
		}
	}
	return false;
}
void solve() {
	//code goes here
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	string word;
	cin >> word;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == word[0]) {
				vector<vector<bool>> visited(n, vector<bool>(m, false));
				if (isPossible(board, word, i, j, n, m, visited)) {
					cout << "true" << endl;
					return;
				}
			}
		}
	}
	cout << "false" << endl;
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