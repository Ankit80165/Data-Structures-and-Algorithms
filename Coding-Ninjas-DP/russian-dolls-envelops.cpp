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
bool comapare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	} else {
		return a.first < b.first;
	}
}
int longestIncSubs(vector<int> widths) {
	int n = widths.size();
	vector<int> lis;
	lis.push_back(widths[0]);
	for (int i = 1; i < n; i++) {
		int currWidth = widths[i];
		int lastWidth = lis[lis.size() - 1];
		if (currWidth > lastWidth) {
			lis.push_back(currWidth);
		} else {
			int index = lower_bound(lis.begin(), lis.end(), currWidth) - lis.begin();
			lis[index] = currWidth;
		}
	}

	return lis.size();
}
int russianEnvelops(int *heights, int *widths, int n) {
	if (n == 1) {
		return 1;
	}
	vector<pair<int, int>> envelops;
	for (int i = 0; i < n; i++) {
		envelops.push_back({heights[i], widths[i]});
	}
	sort(envelops.begin(), envelops.end(), comapare);
	vector<int> sortedWidths;
	for (int i = 0; i < envelops.size(); i++) {
		sortedWidths.push_back(envelops[i].second);
	}
	int maxLen = longestIncSubs(sortedWidths);
	return maxLen;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	int heights[n], widths[n];
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> widths[i];
	}
	int ans = russianEnvelops(heights, widths, n);
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