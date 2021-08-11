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
void helper(queue<int> &q, stack<int> st) {
	if (st.size() == 0) {
		return;
	}
	int top = st.top();
	st.pop();
	helper(q, st);

	int next = q.front();
	q.pop();

	q.push(top);
	q.push(next);
	return;
}
void prinStack(stack<int> st) {
	while (st.size() > 0) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
queue<int>interleaveQueue(queue<int> q) {
	stack<int> st;
	int mid = q.size() / 2;
	// cout << q.size() << endl;
	for (int i = 0; i < mid; i++) {
		st.push(q.front());
		q.pop();
	}
	prinStack(st);
	helper(q, st);
	return q;
}

void printQueue(queue<int> q) {
	while (q.size() > 0) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
void solve() {
	//code goes here
	int n;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	queue<int> result = interleaveQueue(q);
	printQueue(result);
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