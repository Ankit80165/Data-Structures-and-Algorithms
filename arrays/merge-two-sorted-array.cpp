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
void placeInCorrectPos(int *A, int n) {
	int key = A[0];
	int i = 1;
	while (i < n && key > A[i]) {
		A[i - 1] = A[i];
		i++;
	}
	A[i - 1] = key;
	return;
}
void print(int *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
void mergeTwoSortedArrays(int *A, int *B, int n, int m ) {
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (A[i] < B[j]) {
			// cout << A[i] << " " << B[j] << endl;
			i++;
		} else {
			// cout << "here" << endl;
			swap(A[i], B[j]);
			i++;
			placeInCorrectPos(B, m);
		}
		// print(A, n);
		// print(B, m);
	}
	return;
}

void solve() {
	//code goes here
	int n, m;
	cin >> n >> m;
	int A[n], B[m];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	mergeTwoSortedArrays(A, B, n, m);
	print(A, n);
	print(B, m);
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