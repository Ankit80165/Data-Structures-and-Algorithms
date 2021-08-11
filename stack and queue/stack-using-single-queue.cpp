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
	queue<int> q;
	void push(int x) {
		q.push(x);
		int size = q.size();
		while (size > 1) {
			int f = q.front();
			q.pop();
			q.push(f);
			size--;
		}
	}
	int pop() {
		if (q.size() > 0) {
			int f = q.front();
			q.pop();
			return f;
		}
		return -1;
	}
	int top() {
		return q.size() > 0 ? q.front() : -1;
	}
	bool isEmpty() {
		return q.size() > 0 ? false : true;
	}
};
void solve() {
	//code goes here
	myStack s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.push(a);
	}
	for (int i = 0; i < n; i++) {
		int popped = s.pop();
		cout << popped << " ";
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