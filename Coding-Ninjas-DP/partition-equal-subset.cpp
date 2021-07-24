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
bool isPossible(ll *A, int n, int sum, int curr) {
	if (curr == sum) {
		return true;
	}
	if (n <= 0) {
		return false;
	}
	bool o1 = isPossible(A + 1, n - 1, sum, curr + A[0]);
	bool o2 = isPossible(A + 1, n - 1, sum, curr);

	return o1 || o2;
}
// iterative dynamic programming approach
bool isPresentDP(int *A, int n, int sum) {
	// we need to check is this sum is present in the array or not
	bool dp[n + 1][sum + 1];
	// fill first row
	for (int i = 0; i < sum + 1; i++) {
		dp[0][i] = false;
	}
	// fill first col
	for (int i = 0; i < n + 1; i++) {
		dp[i][0] = true;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {
			// col value
			if (A[i - 1] > j) {
				// if current val is greater than the sum, just leave it
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
			}
		}
	}
	return dp[n][sum];
}
// dp...space optimized solution
bool isPresent(int *A, int n, int sum) {
	bool present[sum + 1];
	fill(present, present + sum + 1, false);
	present[0] = true;
	for (int i = 0; i < n; i++) {
		int curr = A[i];
		for (int j = sum; j >= curr; j--) {
			present[j] = present[j] || present[j - A[i]];
		}
	}
	return present[sum];
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum += A[i];
	}
	if (sum % 2 == 1) {
		cout << "false" << endl;
	} else {
		if (isPossible(A, n, sum / 2, 0)) {
			cout << "true" << endl;
		} else {
			cout << "false" << endl;
		}
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