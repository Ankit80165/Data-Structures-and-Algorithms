// krushkal algorithm for finding MST
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
class disjointSet
{
	int *parent, *rank;
	int n;
public:
	disjointSet(int n) {
		this->n = n;
		this->parent = new int[n];
		this->rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	};
	int findParent(int i) {
		if (this->parent[i] == i) {
			return i;
		}
		int res = findParent(parent[i]);
		// path compression
		parent[i] = res;
		return res;
	};
	void unionByRank(int i, int j) {
		int par_i = this->findParent(i);
		int par_j = this->findParent(j);
		if (par_i == par_j) {
			cout << "Both are in same component!";
			return;
		}
		int rank_par_i = this->rank[par_i];
		int rank_par_j = this->rank[par_j];
		if (rank_par_i < rank_par_j) {
			this->parent[par_i] = par_j;
		}
		else if (rank_par_i > rank_par_j) {
			this->parent[par_j] = par_i;
		}
		else {
			// do whatever we want, make anyone as parent
			this->parent[par_i] = par_j;
			this->rank[par_j]++;
		}
	}
	~disjointSet() {
		delete[] this->parent;
		delete[] this->rank;
	};

};
class node {
public:
	int u, v, wt;
	node(int u, int v, int wt) {
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};
bool comapare(node a, node b) {
	return a.wt <= b.wt;
}
void solve() {
	// your code goes here
	int n, e; // n= number of node, e = number of edges
	cin >> n >> e;
	vector<node> edges;
	for (int i = 0; i < e; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		node t = node(u, v, wt);
		edges.push_back(t);
	}
	sort(edges.begin(), edges.end(), comapare);
	disjointSet obj(n);
	std::vector<pair<int, int>> MST;
	int cost = 0;
	for (int i = 0; i < edges.size(); i++) {
		node t = edges[i];
		int u = t.u;
		int v = t.v;
		if (obj.findParent(u) != obj.findParent(v)) {
			cost += t.wt;
			MST.push_back({u, v});
			obj.unionByRank(u, v);
		}
	}
	for (int i = 0; i < MST.size(); i++) {
		cout << MST[i].first << " " << MST[i].second << endl;
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