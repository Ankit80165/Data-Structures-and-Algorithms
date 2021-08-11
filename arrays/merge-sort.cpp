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
void merge(ll *A, int low, int mid, int high) {
	vector<int> temp1;
	vector<int> temp2;
	for (int i = low; i <= mid; i++) {
		temp1.push_back(A[i]);
	}
	for (int i = mid + 1; i <= high; i++) {
		temp2.push_back(A[i]);
	}
	int i = 0, j = 0, k = low;
	while (i < temp1.size() && j < temp2.size()) {
		if (temp1[i] < temp2[j]) {
			A[k] = temp1[i];
			i++;
			k++;
		} else {
			A[k] = temp2[j];
			j++;
			k++;
		}
	}
	while (i < temp1.size()) {
		A[k] = temp1[i];
		i++;
		k++;
	}
	while (j < temp2.size()) {
		A[k] = temp2[j];
		j++;
		k++;
	}
}
void mergeSort(ll *A, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(A, low, mid);
		mergeSort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}
void printArray(ll *A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	ll A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	mergeSort(A, 0, n - 1);
	printArray(A, n);
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