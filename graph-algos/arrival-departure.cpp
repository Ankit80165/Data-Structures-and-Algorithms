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
void dfs(vector<int>v[],
         int n,
         int sv,
         int &currTime,
         vector<bool> &visited,
         vector<pair<int, int>> &res)
{
	visited[sv] = true;
	int start = currTime;
	for (int i = 0; i < v[sv].size(); i++) {
		if (visited[v[sv][i]] == false) {
			currTime++;
			dfs(v, n, v[sv][i], currTime, visited, res);
		}
	}
	int end = ++ currTime;
	cout << sv << " " << start << " " << end << endl;
	res.push_back({start, end});
	return;
}
void solve() {
	//code goes here
	int n, e;
	cin >> n >> e;
	vector<int> v[n];
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		v[f].push_back(s);
	}
	vector<bool> visited(n, false);
	vector<pair<int, int>> res;
	int currTime = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			dfs(v, n, i, currTime, visited, res);
			currTime++;
		}
	}
	// for (int i = 0; i < res.size(); i++) {
	// 	cout << res[i].first << " " << res[i].second << endl;
	// }
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