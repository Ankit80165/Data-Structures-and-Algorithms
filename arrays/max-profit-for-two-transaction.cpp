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
int maxProfitWhenTwoTranAllowed(ll *A, int n) {
	int buyToday[n], sellToday[n];
	// fill buy today
	sellToday[0] = 0;
	int minSoFar = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] < minSoFar) {
			minSoFar = A[i];
		}
		int currProfit = A[i] - minSoFar;
		sellToday[i] = max(sellToday[i - 1], currProfit);
	}
	// fill buy today
	buyToday[n - 1] = 0;
	int maxSoFar = A[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (A[i] > maxSoFar) {
			maxSoFar = A[i];
		}
		int currProfit = maxSoFar - A[i];
		buyToday[i] = max(buyToday[i + 1], currProfit);
	}

	int totalMaxProfit = 0;
	for (int i = 0; i < n; i++) {
		int profit = buyToday[i] + sellToday[i];
		if (profit > totalMaxProfit) {
			totalMaxProfit = profit;
		}
	}

	return totalMaxProfit;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int maxProfit = maxProfitWhenTwoTranAllowed(A, n);
	cout << maxProfit << endl;
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