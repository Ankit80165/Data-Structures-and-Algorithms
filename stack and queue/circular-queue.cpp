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
class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};
class myQueue {
public:
	Node *head;
	Node *tail;
	myQueue() {
		head = NULL;
		tail = NULL;
	}
	push(int x) {
		Node *newNode = new Node(x);
		if (tail == NULL) {
			head = newNode;
			tail = newNode;
			tail->next = head;
		} else {
			tail->next = newNode;
			tail = tail->next;
			tail->next = head;
		}
	}
	int pop() {
		if (tail == NULL) {
			return -1;
		}
		else if (head == tail) {
			int data = head->data;
			Node *temp = head;
			delete(temp);
			head = NULL;
			tail = NULL;
			return data;
		}
		else {
			Node *temp = head;
			head = head->next;
			tail->next = head;
			int data = temp->data;
			delete(temp);
			return data;
		}
	}
	int front() {
		if (head == NULL && tail == NULL) {
			return -1;
		}
		return head->data;
	}
	bool isEmpty() {
		if (head == NULL && tail == NULL) {
			return true;
		}
		return false;
	}
};
void solve() {
	//code goes here
	myQueue q;
	while (1) {
		int a;
		cin >> a;
		if (a == 1) {
			// push
			int x;
			cin >> x;
			q.push(x);
			cout << "data inserted = " << x << endl;
			cout << "front = " << q.front() << endl;
		}
		else if (a == 2) {
			int dataPopped = q.pop();
			cout << "data popped = " << dataPopped << endl;
			cout << "front = " << q.front() << endl;
		}
		else {
			break;
		}
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