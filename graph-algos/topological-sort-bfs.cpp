// this is code for topological sort using bfs
// this algorithm is called kahn's algorithm
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
std::vector<int> topologicalSort(vector<int>v[], queue<int> q, int indegree[], int n) {
	std::vector<int> res;
	while (q.size() > 0) {
		int f = q.front();
		q.pop();
		res.push_back(f);
		for (int i = 0; i < v[f].size(); i++) {
			int adj = v[f][i];
			if (indegree[adj] > 0) {
				indegree[adj]--;
				if (indegree[adj] == 0) {
					q.push(adj);
				}
			}
		}
	}
	return res;
}
void solve() {
	// your code goes here
	int n, e;
	cin >> n >> e;
	int indegree[n] = {};
	std::vector<int> v[n];
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		v[f].push_back(s);
		indegree[s]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> topo = topologicalSort(v, q, indegree, n);
	for (int i = 0; i < topo.size(); i++) {
		cout << topo[i] << " ";
	}
	cout << endl;
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