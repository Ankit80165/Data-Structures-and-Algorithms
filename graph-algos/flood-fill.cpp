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
void helper(int sr,
            int sc,
            vector<vector<int>> &image,
            vector<vector<bool>> &visited,
            int newColor)
{
	// cout << sr << " " << sc << endl;
	int n = image.size();
	int m = image[0].size();

	if (sr < 0 || sr >= n || sc < 0 || sc >= m || visited[sr][sc]) {
		return;
	}
	visited[sr][sc] = true;
	int col = image[sr][sc];
	image[sr][sc] = newColor;
	int dx[] = { -1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	for (int i = 0; i < 4; i++) {
		int rr = sr + dx[i];
		int cc = sc + dy[i];
		if (isValid(rr, cc, n, m) && !visited[rr][cc] && col == image[rr][cc]) {
			helper(rr, cc, image, visited, newColor);
		}
	}

	return;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int n = image.size();
	int m = image[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	helper(sr, sc, image, visited, newColor);
	return image;
}
void solve() {
	// your code goes here
	int n, m;
	cin >> n >> m;
	std::vector<std::vector<int>> v;
	for (int i = 0; i < n; i++) {
		std::vector<int> temp;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
	}
	int sr, sc, newColor;
	cin >> sr >> sc >> newColor;
	std::vector<std::vector<int>> res = floodFill(v, sr, sc, newColor);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

/**** main function ****/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;


	solve();

	return 0;
}