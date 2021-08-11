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
void insertAtEnd(stack<int> &s, int ele) {
	if (s.size() == 0) {
		s.push(ele);
		return;
	}
	int topElement = s.top();
	s.pop();
	insertAtEnd(s, ele);
	s.push(topElement);
	return;
}
void reverseStack(stack<int> &st) {
	if (st.size() == 0) {
		return;
	}
	int topEle = st.top();
	st.pop();
	reverseStack(st);
	insertAtEnd(st, topEle);
	return;
}
void printStack(stack<int> st) {
	while (st.size() > 0) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		st.push(a);
	}
	printStack(st);
	reverseStack(st);
	printStack(st);
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