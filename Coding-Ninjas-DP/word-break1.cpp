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
vector<string> printSentences(string s, vector<string> words) {

	vector<string> res;
	if (s.size() <= 0) {
		res.push_back("");
		return res;
	}
	for (int i = 0; i < s.size(); i++) {
		string temp = s.substr(0, i + 1);
		if (binary_search(words.begin(), words.end(), temp)) {
			string f = temp + " ";
			vector<string> smallOutput = printSentences(s.substr(i + 1, s.size() - i - 1), words);
			for (int i = 0; i < smallOutput.size(); i++) {
				res.push_back(f + smallOutput[i]);
			}
		}
	}
	return res;
}
void solve() {
	//code goes here
	string sentence;
	vector<string> words;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		words.push_back(t);
	}
	cin >> sentence;
	sort(words.begin(), words.end());
	vector<string> res = printSentences(sentence, words);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
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