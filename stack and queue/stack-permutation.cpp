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
bool isStackPermutation(vector<int> input, vector<int> output) {
	stack<int> st;
	int n = input.size();
	vector<int> result;
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] != output[j]) {
			st.push(input[i]);
		} else {
			result.push_back(input[i]);
			j++;
			while (st.size() > 0 && st.top() == output[j]) {
				// st.pop();
				result.push_back(st.top());
				st.pop();
				j++;
			}
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	if (st.size() != 0) {
		return false;
	}
	return true;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	vector<int> input(n), output(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> output[i];
	}
	if (isStackPermutation(input, output)) {
		cout << "stack permutation" << endl;
	} else {
		cout << "Not a stack permutation" << endl;
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