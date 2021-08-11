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
bool checkBipartite(vector<int> v[], int n, int sv, vector<int> &color) {
	color[sv] = 0;
	queue<int> q;
	q.push(sv);

	while (q.size() > 0) {
		int f = q.front();
		q.pop();

		for (int i = 0; i < v[f].size(); i++) {
			int adj = v[f][i];
			if (color[adj] == -1) {
				q.push(adj);
				if (color[f] == 1) {
					color[adj] = 0;
				} else {
					color[adj] = 1;
				}
			} else {
				if (color[adj] == color[f]) {
					return false;
				}
			}
		}
	}

	return true;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	int edges[n][n];
	vector<int> v[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> edges[i][j];
			if (edges[i][j] == 1) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}

	vector<int> color(n, -1);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			if (checkBipartite(v, n, i, color) == false) {
				cout << "not bipartite" << endl;
				return;
			}
		}
	}
	cout << "bipartite" << endl;
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