// minimum path to all nodes from a source node
// this is using priority queue
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
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
ll GCD(ll x, ll y) {return __gcd(x, y);}
ll LCM(ll x, ll y) {return (x * y) / __gcd(x, y);}
void Dijkstra(std::vector<pi> v[], int src, int n, std::vector<bool> &visited) {
	priority_queue<pi, std::vector<pi>, greater<pi>> pq;
	pq.push(make_pair(0, src)); // weight and node

	while (pq.size() > 0) {
		cout << "inside while" << endl;
		pi t = pq.top(); //t.first = weight, t.second = node
		pq.pop();
		if (visited[t.second] == true) {
			continue;
		}
		visited[t.second] = true;
		cout << t.second << " ->" << t.first << endl;

		for (int i = 0; i < v[t.second].size(); i++) {
			pi adj = v[t.second][i];
			int adjacent = adj.first;
			int weight = adj.second;
			if (visited[adjacent] == false) {
				pq.push(make_pair(weight + t.first, adjacent));
			}
		}
	}
	return;
}
void solve() {
	// your code goes here
	int n, e;
	cin >> n >> e;
	std::vector<pi> v[n];
	for (int i = 0; i < e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		v[f].push_back(make_pair(s, w));
		v[s].push_back(make_pair(f, w));
	}
	int src;
	cin >> src;
	std::vector<bool> visited(n, false);
	Dijkstra(v, src, n, visited);
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