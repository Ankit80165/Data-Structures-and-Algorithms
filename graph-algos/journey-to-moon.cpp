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
void dfs(vector<int> edges[], int n, int sv, vector<bool> &visited, int &nodeCount) {
	// cout << sv << endl;
	visited[sv] = true;
	nodeCount++;
	for (int i = 0; i < edges[sv].size(); i++) {
		if (visited[edges[sv][i]] == false) {
			dfs(edges, n, edges[sv][i], visited, nodeCount);
		}
	}
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
		v[s].push_back(f);
	}
	vector<bool> visited(n, false);
	vector<int> nodes;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			int nodeCount = 0;
			dfs(v, n, i, visited, nodeCount);
			nodes.push_back(nodeCount);
		}
	}
	int size = nodes.size();
	for (int i = size - 2; i >= 0; i--) {
		nodes[i] += nodes[i + 1];
	}

	long long int totalWays = 0;
	for (int i = 0; i < size - 1; i++) {
		int currVal = nodes[i] - nodes[i + 1];
		long long int temp = ((currVal % mod) * (nodes[i + 1] % mod)) % mod;
		totalWays = ((totalWays % mod) + (temp % mod)) % mod;
	}
	cout << totalWays << endl;
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