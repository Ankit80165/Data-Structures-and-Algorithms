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
typedef pair<int, pair<int, int>> pp;
typedef vector<ll> vll;
typedef vector<pll> vpll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
ll GCD(ll x, ll y) {return __gcd(x, y);}
ll LCM(ll x, ll y) {return (x * y) / __gcd(x, y);}

void solve() {
	// your code goes here
	int n, e;
	cin >> n >> e;
	std::vector<pair<int, int>> v[n];
	for (int i = 0; i < e; i++) {
		int f, s, w;
		cin >> f >> s >> w;
		v[f].push_back({s, w});
		v[s].push_back({f, w});
	}

	std::vector<bool> MST(n, false);
	std::vector<int> Parent(n, -1);

	priority_queue<pp, std::vector<pp>, greater<pp>> pq;
	pair<int, int> temp = make_pair(0, -1);
	pp p = make_pair(0, temp);
	pq.push(p);
	while (pq.size() > 0) {
		pp t = pq.top();
		pq.pop();
		int node = t.second.first;
		int parent = t.second.second;
		int weight = t.first;
		cout << weight << " " << node << endl;
		if (MST[node] == true) {
			// if it is already taken, just move on
			continue;
		}
		Parent[node] = parent;
		MST[node] = true;
		for (int i = 0; i < v[node].size(); i++) {
			int adj = v[node][i].first;
			int val = v[node][i].second;
			if (MST[adj] == false) {
				pq.push({val, {adj, node}});
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << Parent[i] << "->" << i << endl;
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