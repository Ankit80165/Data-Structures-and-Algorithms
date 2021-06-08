// implementation of bellman ford algoritm
// time complexity = O((N-1)*e)
// space complexity = O(N)
// N = total number of edges
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
class node {
public:
	int u, v, wt;
	node(int u, int v, int wt) {
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};
void solve() {
	// your code goes here
	int n, e;
	cin >> n >> e;
	std::vector<node> edges;
	for (int i = 0; i < e; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back(node(u, v, wt));
	}
	std::vector<int> dist(n, INT_MAX);
	int src;
	cin >> src;
	dist[src] = 0;
	for (int i = 1; i <= n - 1; i++) {
		// (n-1) times relaxation
		for (int j = 0; j < edges.size(); j++) {
			int u = edges[i].u;
			int v = edges[i].v;
			int wt = edges[i].wt;
			if (dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}
	// last relaxation to check if negative cycle present or not
	for (int i = 0; i < edges.size(); i++) {
		if (dist[edges[i].u] + edges[i].wt < dist[edges[i].v]) {
			cout << "Nefative Cycle is present" << endl;
			return;
		}
	}
	cout << "No Negative is present" << endl;
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