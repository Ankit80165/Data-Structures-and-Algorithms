// for m-coloring problem if m > 2 we can always color all the nodes
// if(m == 1) we can only color if all nodes are disconnected from any other nodes
// for(m == 2) if the graph has a cycle of odd length we cant color , if all cycles has even length
// we can color the graph
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
bool checkBipartite(std::vector<int> v[], int n, std::vector<bool> &visited, std::vector<int> &color, int sv) {
	queue<int> q;
	q.push(sv);
	color[sv] = 0;
	visited[sv] = true;
	while (q.size() > 0) {
		int f = q.front();
		q.pop();
		for (int i = 0; i < v[f].size(); i++) {
			int adjacent = v[f][i];
			if (color[adjacent] == -1) {
				q.push(adjacent);
				if (color[f] == 0) {
					color[adjacent] = 1;
				} else {
					color[adjacent] = 0;
				}
				visited[adjacent] = true;
			} else {
				if (color[f] == color[adjacent]) {
					cout << endl;
					return false;
				}
			}
		}
	}
	return true;
}
void solve() {
	// your code goes here
	int n, e;
	cin >> n >> e;
	std::vector<int> v[n];
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		v[f].push_back(s);
		v[s].push_back(f);
	}
	std::vector<bool> visited(n, false);
	std::vector<int> color(n, -1);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			if (checkBipartite(v, n, visited, color, i) == false) {
				cout << "Not bipartite" << endl;
				return;
			}
		}
	}
	cout << "Bipartite" << endl;
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