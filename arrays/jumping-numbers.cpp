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
ll calculate(vector<ll> num) {
	ll res = 0;
	for (int i = 0; i < num.size(); i++) {
		res = res * 10 + num[i];
	}
	return res;
}
bool isJumpNum(vector<ll> nums) {
	if (nums.size() == 1) return true;
	for (int i = 1; i < nums.size(); i++) {
		if (abs(nums[i] - nums[i - 1]) != 1) {
			return false;
		}
	}
	return true;
}
void jumpNumRec(ll index, vector<ll> number, vector<ll> &allJumpNums) {
	if (index >= number.size()) {
		ll current = calculate(number);
		if (isJumpNum(number)) {
			allJumpNums.push_back(current);
		}
		return;
	}
	ll prevDigit = number[index - 1];
	if (prevDigit == 0) {
		number[index] = 1;
		jumpNumRec(index + 1, number, allJumpNums);
	} else {
		number[index] = prevDigit - 1;
		jumpNumRec(index + 1, number, allJumpNums);
		number[index] = prevDigit + 1;
		jumpNumRec(index + 1, number, allJumpNums);

		return;
	}
}
ll findJumpingNum(ll n) {
	vector<ll> digits;
	ll num = n;
	while (num > 0) {
		ll d = num % 10;
		digits.push_back(d);
		num = num / 10;
	}
	reverse(digits.begin(), digits.end());
	vector<ll> number(digits.size());
	vector<ll> allJumpNums;
	for (ll i = 0; i <= digits[0]; i++) {
		number[0] = i;
		jumpNumRec(1, number, allJumpNums);
	}
	for (int i = allJumpNums.size() - 1; i >= 0; i--) {
		if (allJumpNums[i] <= n) {
			return allJumpNums[i];
		}
	}
	return 0;
}
void solve() {
	//code goes here
	ll n;
	cin >> n;
	ll jumpingNum = findJumpingNum(n);
	cout << jumpingNum << endl;
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