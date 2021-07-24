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
// brute force recursive approach
int maxSumIncSubsequence(ll *A, int n, int prev) {
	// base case
	if (n == 0) {
		return 0;
	}
	if (A[0] > prev) {
		int o1 = maxSumIncSubsequence(A + 1, n - 1, prev);
		int o2 = A[0] + maxSumIncSubsequence(A + 1, n - 1, A[0]);
		return max(o1, o2);
	} else {
		return maxSumIncSubsequence(A + 1, n - 1, prev);
	}
}
// iterative dynamic programming
int maxSumIncSubsequenceDP(ll *A, int n) {
	int dp[n];
	for (int i = 0; i < n; i++) {
		dp[i] = A[i];
	}
	int maxVal = dp[0];
	for (int i = 1; i < n; i++) {
		ll currMax = dp[i];
		for (int j = i - 1; j >= 0; j--) {
			if (A[i] > A[j]) {
				currMax = max(currMax, dp[j] + A[i]);
			}
		}
		dp[i] = currMax;
		if (dp[i] > maxVal) {
			maxVal = dp[i];
		}
	}
	if (maxVal > 0) return maxVal;
	return 0;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int maxSum = maxSumIncSubsequenceDP(A, n);
	cout << maxSum << endl;
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