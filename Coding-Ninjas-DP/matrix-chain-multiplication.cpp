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
// recursive approach
ll matrixChain(ll *A, int size, int s, int end) {
	if (s >= end) {
		return 0;
	}
	ll res = INT_MAX;
	for (int i = s; i < end; i++) {
		ll o1 = matrixChain(A, size, s, i) + matrixChain(A, size, i + 1, end) + A[s - 1] * A[i] * A[end];
		res = min(res, o1);
	}
	return res;
}
// dynamic programming approach
ll matrixChainDP(ll *A, int size) {
	// if the array is length of n, then the no.of matrix is n-1;
	// i will use dp of size (n-1)*(n-1)
	int len = size - 1;
	ll dp[size - 1][size - 1];
	// we will use gap method
	for (int i = len - 1; i >= 0; i--) {
		for (int j = 0; j < len; j++) {
			if (i > j) {
				dp[i][j] = -1;
				continue;
			}
			else if (i == j) {
				dp[i][j] = 0;
			}
			else if (j - i == 1) {
				dp[i][j] = A[i] * A[j] * A[j + 1];
			}
			else {
				ll minVal = INT_MAX;
				// this is the most complicated part...try to visualize
				for (int k = i; k < j; k++) {
					minVal = min((dp[i][k] + dp[k + 1][j] + A[i] * A[k + 1] * A[j + 1]), minVal);
				}
				dp[i][j] = minVal;
			}
		}
	}
	return dp[0][size - 2];
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	ll res = matrixChainDP(A, n);
	cout << "res = " << res << endl;
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