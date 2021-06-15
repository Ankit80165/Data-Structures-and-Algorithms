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
void dfs(vector<int>v[], int n, vector<bool>&visited, int s, stack<int>&st) {
	visited[s] = true;
	for (int i = 0; i < v[s].size(); i++) {
		if (visited[v[s][i]] == false) {
			dfs(v, n, visited, v[s][i], st);
		}
	}
	st.push(s);
	return;
}
void dfsOnTranspos(vector<int>v[], int n, vector<bool>&visited, int s) {
	visited[s] = true;
	for (int i = 0; i < v[s].size(); i++) {
		if (visited[v[s][i]] == false) {
			dfsOnTranspos(v, n, visited, v[s][i]);
		}
	}
	return;
}
void solve() {
	//code goes here
	int n, e;
	cin >> n >> e;
	std::vector<int> v[n];
	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		v[f].push_back(s);
	}
	std::vector<bool> visited(n, false);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(v, n, visited, i, st);
		}
	}
	std::vector<int> transpos[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		for (int j = 0; j < v[i].size(); j++) {
			transpos[v[i][j]].push_back(i);
		}
	}
	int count = 0;
	while (st.size() > 0) {
		if (visited[st.top()] == false) {
			count++;
			dfsOnTranspos(transpos, n, visited, st.top());
		}
		st.pop();
	}
	cout << count << endl;
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