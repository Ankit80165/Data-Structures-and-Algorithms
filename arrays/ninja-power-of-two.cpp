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
vector < vector < int > > numberPattern(int n) {

	// Write your code here
	vector<vector<int>> result;
	int curr = 1;
	for (int i = 1; i <= n; i++) {
		int val = pow(2, i - 1);
		vector<int> temp;
		for (int j = 1; j <= val; j++) {
			temp.push_back(curr);
			if (curr == 9) {
				curr = 1;
			} else {
				curr++;
			}
		}
		result.push_back(temp);
	}
	return result;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	vector<vector<int>> res = numberPattern(n);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
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