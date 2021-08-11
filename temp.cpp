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
class Base {
private:
	int a;
protected:
	int b;
public:
	int c;

	setData() {
		a = 10; b = 20; c = 30;
	}
	showA() {
		cout << a << endl;
	}
};



class Derived : private Base {
private:
	int dA = 10;
	static int dc;
public:

	Derived() {
		setData();
		showA() ;
		cout << b << endl;
		cout << c << endl;
		cout << "constructor" << endl;
	}
	static void showSData() {
		cout << dc;
	}
};
int Derived :: dc = 100;
void solve() {
	//code goes here
	// Derived::showSData();

	const int x = 10;
	int y = 20;
	const int *p = &y;
	cout << *p << endl;

	// dangling pointer
	int *p1, *q1;
	p1 = new int;
	*p1 = 22;
	q1 = p1;
	// delete p1;    //  this statement does this
	*q1 = 300;


	// reference variables
	int a = 100001;
	int &p2 = a;
	int b = 12;
	p2 = b;
	return;
}
void fun(int a) {
	cout << a << endl;
}
void fun(int a, int b) {
	cout << a*b << endl;
}
int fun(int a, int b, int c) {
	return a * b * c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;

	solve();
	return 0;
}