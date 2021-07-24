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
int smallestSubarray(ll *A, int n, int x) {
	int start = 0, end = 0;
	int minLen = INT_MAX;
	int sum = 0;
	while (end < n) {
		while (end < n && sum <= x) {
			sum += A[end];
			end++;
		}
		while (start < end && sum > x) {
			int currLen = (end - start);
			minLen = min(minLen, currLen);
			sum -= A[start];
			start++;
		}
	}
	return minLen;
}
void solve() {
	//code goes here
	int n, x;
	cin >> n >> x;

	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int minLen = smallestSubarray(A, n, x);
	cout << minLen << endl;
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