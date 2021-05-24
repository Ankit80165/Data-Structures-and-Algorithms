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
void BFS(int **edges, int n, std::vector<bool> &visited, int sv) {
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	while (q.size() > 0) {
		int f = q.front();
		q.pop();
		cout << f << endl;
		for (int i = 0; i < n; i++) {
			if (edges[f][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}
void solve() {
	// your code goes here
	int n, e;
	cin >> n >> e;
	int **edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}
	// taking edges inputs
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	std::vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			BFS(edges, n, visited, i);
		}
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