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
int findCelebrityOptimized(vector<vector<int>> matrix, int n) {
	int possible = 0;
	for (int i = 1; i < n; i++) {
		if (matrix[possible][i] == 1) {
			possible = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (matrix[possible][i] == 1) {
			return -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == possible) continue;
		if (matrix[i][possible] == 0) {
			return -1;
		}
	}
	return possible;
}
// stack based solution
int findCelebrity(vector<vector<int>> matrix, int n) {
	stack<int> st;
	for (int i = 0; i < n; i++) {
		st.push(i);
	}
	while (st.size() > 1) {
		int possible1 = st.top();
		st.pop();
		int possible2 = st.top();
		st.pop();

		if (matrix[possible1][possible2] == 1) {
			st.push(possible2);
		} else {
			st.push(possible1);
		}
	}
	int possibleCelebrity = st.top();
	for (int i = 0; i < n; i++) {
		if (matrix[possibleCelebrity][i] == 1) {
			return -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == possibleCelebrity) continue;
		if (matrix[i][possibleCelebrity] == 0) {
			return -1;
		}
	}
	return possibleCelebrity;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int celebrity = findCelebrityOptimized(matrix, n);
	if (celebrity == -1) {
		cout << "No celebrity" << endl;
	} else {
		cout << celebrity + 1 << endl;
	}
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