// brute force approach for building MST
// time complexity O(n^2)
// space complexity O(n)
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
	// initialization of vectors
	std::vector<int> keys(n, INT_MAX);
	std::vector<bool> MST(n, false);
	std::vector<int> Parent(n, -1);
	keys[0] = 0;

	for (int c = 0; c < n - 1; c++) {
		// cz, we need to create n-1 edges
		int minVal = INT_MAX, node;
		for (int i = 0; i < n; i++) {
			if (MST[i] == false && keys[i] < minVal) {
				minVal = keys[i];
				node = i; // picked node
			}
		}
		cout << node << endl;
		MST[node] = true; // mark the picked node
		for (auto it : v[node]) {
			int adj = it.first;
			int val = it.second;
			if (MST[adj] == false && val < keys[adj]) {
				Parent[adj] = node;
				keys[adj] = val;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		// as 0 is root parent willl be -1
		cout << Parent[i] << " " << i << endl;
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