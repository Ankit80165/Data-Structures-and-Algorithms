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
vector<int> getPrevMinElements(int *A, int n) {
	stack<int> st;
	vector<int> result(n, -1);
	st.push(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		while (st.size() > 0 &&  A[i] < A[st.top()]) {
			result[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	return result;
}
vector<int> getNextSmallerElements(int *A, int n) {
	stack<int> st;
	vector<int> result(n, n);
	st.push(0);
	for (int i = 1; i < n; i++) {
		while (st.size() > 0 &&  A[i] < A[st.top()]) {
			result[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	return result;
}
void printVector(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
void printResult(vector<int> vec, int *A) {
	for (int i = 0; i < vec.size(); i++) {
		cout << A[vec[i]] << " ";
	}
	cout << endl;
}
void solve() {
	//code goes here
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector<int> prevMin = getPrevMinElements(A, n);
	printVector(prevMin);
	vector<int> nextMin = getNextSmallerElements(A, n);
	printVector(nextMin);
	int maxArea = 0;
	for (int i = 0; i < prevMin.size(); i++) {
		int leftBoundary = prevMin[i] + 1;
		int rightBoundary = nextMin[i] - 1;
		int currArea = (rightBoundary - leftBoundary + 1) * A[i];
		maxArea = max(maxArea, currArea);
	}
	cout << maxArea << endl;
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