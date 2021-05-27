// cycle detection in directed graph
// here we will maintain two visited array
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
bool checkCycle(std::vector<int> v[], std::vector<bool> &visited, std::vector<bool> &dfsVisited, int sv) {
	visited[sv] = true;
	dfsVisited[sv] = true;
	for (int i = 0; i < v[sv].size(); i++) {
		if (visited[v[sv][i]] == false) {
			if (checkCycle(v, visited, dfsVisited, v[sv][i])) return true;
		} else if (dfsVisited[v[sv][i]]) {
			return true;
		}
	}
	dfsVisited[sv] = false;
	return false;
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
	}
	std::vector<bool> visited(n, false);
	std::vector<bool> dfsVisited(n, false);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			if (checkCycle(v, visited, dfsVisited, i)) {
				cout << "cycle is present" << endl;
				return;
			}
		}
	}
	cout << "No cycle is present" << endl;
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