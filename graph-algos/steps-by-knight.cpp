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
int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n, std::vector<vector<bool>> &visited) {
	// Code here
	int px = KnightPos[0] - 1;
	int py = KnightPos[1] - 1;

	int tx = TargetPos[0] - 1;
	int ty = TargetPos[1] - 1;

	queue<pair<int, int>> q;
	q.push(make_pair(px, py));
	q.push(make_pair(-1, -1));
	visited[px][py] = true;
	int minSteps = 0;
	while (q.size() > 0) {
		pair<int, int> p = q.front();
		q.pop();
		if (p.first == -1 && p.second == -1) {
			if (q.size() == 0) {
				break;
			} else {
				q.push(make_pair(-1, -1));
				minSteps++;
			}
		} else {
			if (p.first == tx && p.second == ty) {
				return minSteps;
			}
			int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1};
			int dy[] = {1, -1, -2, -2, -1, 1, 2, 2};
			for (int i = 0; i < 8; i++) {
				int rr = p.first + dx[i];
				int cc = p.second + dy[i];
				if (isValid(rr, cc, n) && visited[rr][cc] == false) {
					q.push(make_pair(rr, cc));
					visited[rr][cc] = true;
				}
			}
		}
	}
	return -1;
}
void solve() {
	// your code goes here
	std::vector<int> position, target;
	int px, py, tx, ty, n;
	cin >> n;
	cin >> px >> py;
	cin >> tx >> ty;
	position.push_back(px);
	position.push_back(py);
	target.push_back(tx);
	target.push_back(ty);
	std::vector<std::vector<bool> > visited(n, std::vector<bool> (n, false));
	int minSteps = minStepToReachTarget(position, target, n, visited);
	cout << minSteps << endl;
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