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
int minOperationToMakeArrayPalindrome(ll *A, int n) {
	if (n  == 1) {
		return 0;
	}
	int operation = 0;
	int i = 0, j = n - 1;
	while (i < j) {
		if (A[i] == A[j]) {
			i++;
			j--;
		}
		else if (A[i] > A[j]) {
			j--;
			A[j] += A[j + 1];
			operation++;
		}
		else {
			i++;
			A[i] += A[i - 1];
			operation++;
		}
	}

	return operation;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int minOp = minOperationToMakeArrayPalindrome(A, n);
	cout << minOp << endl;
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