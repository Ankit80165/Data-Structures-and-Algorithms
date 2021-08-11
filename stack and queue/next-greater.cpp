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
vector<int> nextGreaterElement(int *A, int n) {
	vector<int> result(n, -1);
	stack<int> st;
	st.push(0);
	for (int i = 1; i < n; i++) {
		int currElement = A[i];
		while (st.size() > 0 && A[st.top()] < currElement) {
			result[st.top()] = currElement;
			st.pop();
		}
		st.push(i);
	}
	return result;
}
void printResult(vector<int> v) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int> result = nextGreaterElement(A, n);
	printResult(result);
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