// cycle detection in a undirected graph using BFS
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
// function to detect cycle
bool isCyclePresentInCurrentComponent(std::vector<int> v[], int n, std::vector<bool> &visited, int sv) {
	queue<pair<int, int>> q;
	q.push(make_pair(sv, -1));
	visited[sv] = true;
	while (q.size() > 0) {
		pair<int, int> p = q.front();
		q.pop();
		int parent = p.second;
		int currVal = p.first;
		// cout << p.first << " " << p.second << endl;
		for (int i = 0; i < v[currVal].size(); i++) {
			if (parent != -1 && v[currVal][i] != parent && visited[v[currVal][i]]) {
				// cout << "parent = " << parent << endl;
				// cout << "currVal =" << currVal << endl;
				// cout << "adjacent =" << v[currVal][i] << endl;
				return true;
			}
			if (visited[v[currVal][i]] == false) {
				// cout << "adja = " << v[currVal][i] << endl;
				q.push(make_pair(v[currVal][i], currVal));
				visited[v[currVal][i]] = true;
			}
		}
	}
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
		v[s].push_back(f);
	}
	std::vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			if (isCyclePresentInCurrentComponent(v, n, visited, i)) {
				cout << "Cycle is present" << endl;
				return;
			}
		}
	}
	cout << "Cycle is not present" << endl;
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