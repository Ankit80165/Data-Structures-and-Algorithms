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
vector<int> findFirstNegInteger(int *A, int n, int k) {
	vector<int> result;
	deque<int> dq;
	for (int i = 0; i < k; i++) {
		if (A[i] < 0) {
			dq.push_back(i);
		}
	}
	result.push_back(A[dq.front()]);
	for (int i = k; i < n; i++) {
		while (dq.size() > 0 && dq.front() <= (i - k)) {
			dq.pop_front();
		}
		if (A[i] < 0) {
			dq.push_back(i);
		}
		if (dq.size() > 0) {
			result.push_back(A[dq.front()]);
		} else {
			result.push_back(0);
		}
	}
	return result;
}
void printVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
void solve() {
	//code goes here
	int n, k;
	cin >> n >> k;
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int> result = findFirstNegInteger(A, n, k);
	printVector(result);
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