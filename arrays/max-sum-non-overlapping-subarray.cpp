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
void print(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
int maxSubarray(ll *A, int n, int k) {
	// for left part
	vector<int> left, right;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += A[i];
	}
	left.push_back(sum);
	int start = 0;
	for (int i = k; i < n - k; i++) {
		sum -= A[start];
		start++;
		sum += A[i];
		int back = left.back();
		left.push_back(max(back, sum));
	}
	// for right part
	sum = 0;
	start = n - 1;
	for (int i = n - 1; i >= (n - k); i--) {
		sum += A[i];
	}
	right.push_back(sum);
	for (int i = (n - k - 1); i >= k; i--) {
		sum -= A[start];
		start--;
		sum += A[i];
		int back = right.back();
		right.push_back(max(sum, back));
	}
	reverse(right.begin(), right.end());
	// print
	// print(left);
	// print(right);
	int maxSum = INT_MIN;
	for (int i = 0; i < left.size(); i++) {
		int curr = left[i] + right[i];
		if (curr > maxSum) {
			maxSum = curr;
		}
	}
	return maxSum;
}
void solve() {
	//code goes here
	int n, k;
	cin >> n >> k;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	ll ans = maxSubarray(A, n, k);
	cout << ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}