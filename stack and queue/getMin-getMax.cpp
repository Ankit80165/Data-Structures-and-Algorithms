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
class myStack {
public:
	stack<int> st;
	int minEle = INT_MAX;
	void push(int x) {
		if (x > minEle) {
			st.push(x);
		} else {
			int ele = 2 * x - minEle;
			minEle = x;
			st.push(ele);
		}
	}
	int pop() {
		if (st.size() < 0) {
			return -1;
		}
		if (st.top() >= minEle) {
			int val = st.top();
			st.pop();
			return val;
		} else {
			int ele = minEle;
			int result = st.top();
			st.pop();
			int prevMin = 2 * ele - result;
			minEle = prevMin;
			return ele;
		}
	}
	int top() {
		if (st.size() > 0) {
			return st.top();
		} else {
			return -1;
		}
	}
	int getMin() {
		return minEle;
	}
	int getMax() {}
};
void solve() {
	//code goes here
	int n;
	cin >> n;
	myStack s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.push(a);
	}
	for (int i = 0; i < n; i++) {
		cout << "min before remove =" << s.getMin() << endl;
		cout << "now removed ele =" << s.pop() << endl;
		cout << "min after remove =" << s.getMin() << endl << endl;
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