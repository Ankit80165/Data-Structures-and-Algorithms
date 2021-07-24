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
bool isPalindrome(string s, int i, int j) {

	while (i < j) {
		// cout << "ans" << endl;
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}
void allPartions(string &s, int start, vector<vector<string>> &ans, vector<string> &curr) {

	if (start >= s.size()) {
		ans.push_back(curr);
		return;
	}
	for (int i = start; i <= s.size() - 1; i++) {
		if (isPalindrome(s, start, i)) {

			curr.push_back(s.substr(start, i - start + 1));
			allPartions(s, i + 1, ans, curr);
			curr.pop_back();
		}
	}
	return;
}
void solve() {
	//code goes here
	string s;
	cin >> s;

	vector<string> curr;
	vector<vector<string>> ans;

	allPartions(s, 0, ans, curr);


	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
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