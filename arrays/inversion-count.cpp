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
int merge(int *A, int low, int mid, int high) {
	int count = 0;
	vector<int> firstHalf, secondHalf;
	for (int i = low; i <= mid; i++) {
		firstHalf.push_back(A[i]);
	}
	for (int i = mid + 1; i <= high; i++) {
		secondHalf.push_back(A[i]);
	}
	int i = 0, j = 0, k = low;
	while (i < firstHalf.size() && j < secondHalf.size()) {
		if (firstHalf[i] <= secondHalf[j]) {
			A[k] = firstHalf[i];
			i++; k++;
		}
		else {
			A[k] = secondHalf[j];
			count += (firstHalf.size() - i);
			j++;
			k++;
		}
	}
	while (i < firstHalf.size()) {
		A[k] = firstHalf[i];
		i++; k++;
	}
	while (j < secondHalf.size()) {
		A[k] = secondHalf[j];
		j++; k++;
	}

	return count;
}
int inversionCount(int *A, int low, int high, int &count) {
	if (low < high) {
		int mid = (low + high) / 2;
		int c1 = inversionCount(A, low, mid, count);
		int c2 = inversionCount(A, mid + 1, high, count);

		int c = merge(A, low, mid, high);
		return c1 + c2 + c;
	}
	return 0;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int count = inversionCount(A, 0, n - 1, count);
	cout << count << endl;
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