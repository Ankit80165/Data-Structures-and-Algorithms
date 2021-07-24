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
// application of binary search
int medianOfArrays(vector<int> A1, vector<int> A2) {
	if (A1.size() > A2.size()) {
		return medianOfArrays(A2, A1);
	}
	int n1 = A1.size();
	int n2 = A2.size();
	int median = (n1 + n2) / 2;
	int low = max(0, median - n2);
	int high = min(median, n1);
	while (low <= high) {
		int cut1 = (low + high) / 2;
		int cut2 = median - cut1;
		int l1, l2, r1, r2;
		l1 = cut1 == 0 ? INT_MIN : A1[cut1 - 1];
		l2 = cut2 == 0 ? INT_MIN : A2[cut2 - 1];
		r1 = cut1 == n1 ? INT_MAX : A1[cut1];
		r2 = cut2 == n2 ? INT_MAX : A2[cut2];
		if (l1 <= r2 && l2 <= r1) {
			if ((n1 + n2) % 2 == 1) {
				return min(r1, r2);
			} else {
				int o1 = max(l1, l2);
				int o2 = min(r1, r2);
				return (o1 + o2) / 2;
			}
		}
		else if (l1 > r2) {
			high = cut1 - 1;
		} else {
			low = cut1 + 1;
		}

	}
}

void solve() {
	//code goes here
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> A1(n1);
	vector<int> A2(n2);
	for (int i = 0; i < n1; i++) {
		cin >> A1[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> A2[i];
	}
	int ans = medianOfArrays(A1, A2);
	cout << ans << endl;
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