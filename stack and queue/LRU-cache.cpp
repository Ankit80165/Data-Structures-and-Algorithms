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
	Node *next, *prev;
	Node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
	}
};
class LRU {
public:
	int size;
	map<int, Node*> present;
	Node *head, *tail;
	LRU(int s) {
		size = s;
		head = new Node(INT_MAX);
		tail = new Node(INT_MAX);
		head->prev = NULL;
		head->next = tail;
		tail->prev = head;
		tail->next = NULL;
	}
	void putKeyAndValue(int k, int value) {
		if (present.find(k) != present.end()) {
			present[k]->data = value;
		} else {
			if (present.size() == size) {
				Node *prevNode = tail->prev;
				Node *prevOfPrev = prevNode->prev;
				if (prevNode == head) {
					return;
				} else {
					prevOfPrev->next = tail;
					tail->prev = prevOfPrev;
					delete(prevNode);
				}
			}
			Node *secondNode = head->next;
			Node *newNode = new Node(value);
			newNode->next = secondNode;
			secondNode->prev = newNode;
			head->next = newNode;
			newNode->prev = head;
			present[k] = newNode;
		}
	}
	int getValueOfKey(int key) {
		if (present.find(key) == present.end()) {
			return -1;
		} else {
			Node *currNode = present[key];
			int value = currNode->data;
			Node *prevNode = currNode->prev;
			Node *nextNode = currNode->next;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			// now curr nod act as new node
			// we have to insert it to the head
			Node *secondNode = head->next;
			secondNode->prev = currNode;
			currNode->next = secondNode;
			currNode->prev = head;
			head->next = currNode;

			return value;
		}
	}
};
void solve() {
	//code goes here
	int n;
	cin >> n;
	LRU l(n);
	while (1) {
		int a;
		cin >> a;
		if (a == 1) {
			cout << "enter key and value to put" << endl;
			int key, value;
			cin >> key >> value;
			l.putKeyAndValue(key, value);
		}
		else if (a == 2) {
			cout << "enter to get value" << endl;
			int key;
			cin >> key;
			int d = l.getValueOfKey(key);
			cout << "value = " << d << endl;
		} else {
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