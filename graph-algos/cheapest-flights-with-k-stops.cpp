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
int dfs(vector<pair<int, int>> v[], int size, int src, int dst, int k, vector<bool> &visited) {
	if (src == dst) {
		if (k >= -1) {
			return 0;
		} else {
			return INT_MAX;
		}
	}
	if (k <= -1) {
		return INT_MAX;
	}

	visited[src] = true;
	int currMin = INT_MAX;
	for (int i = 0; i < v[src].size(); i++) {
		int adj = v[src][i].first;
		int weight = v[src][i].second;
		if (visited[adj] == false) {
			int o1 = dfs(v, size, adj, dst, k - 1, visited);
			if (o1 >= INT_MAX) {
				o1 = INT_MAX;
			} else {
				o1 += weight;
			}
			currMin = min(currMin, o1);
		}
	}
	visited[src] = false;
	return currMin;
}
int minimumCostPath(vector<pair<int, int>> v[], int n, int src, int dst, int k) {
	priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq;
	pq.push({0, {src, k + 1}});
	while (pq.size() > 0) {
		pair<int, pair<int, int>> t = pq.top();
		pq.pop();
		int currNode = t.second.first;
		int steps = t.second.second;
		int cost = t.first;
		if (steps < 0) {
			continue;
		}
		if (dst == currNode) {
			return cost;
		}

		for (int i = 0; i < v[currNode].size(); i++) {
			int adj = v[currNode][i].first;
			int weight = v[currNode][i].second;
			pq.push({weight + cost, {adj, steps - 1}});
		}
	}

	return -1;
}
void solve() {
	//code goes here
	int n, k , e;
	cin >> n >> k >> e;
	vector<pair<int, int>> v[n];
	for (int i = 0; i < e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		v[f].push_back({s, w});
	}
	int src, dst;
	cin >> src >> dst;
	vector<bool> visited(n, false);
	int minCost = minimumCostPath(v, n, src, dst, k);
	cout << minCost << endl;
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