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
class heap {
private:
	int n;
	vector<int> elements;
public:
	heap(int n, vector<int> ele) {
		this->n = n;
		for (int i = 0; i < ele.size(); i++) {
			this->elements.push_back(ele[i]);
		}
		heapifyTopDown();
		printElements();
	}
	//normal functions
	void insertElements(int elementToBeInserted) {
		this->elements.push_back(elementToBeInserted);
		int child = this->elements.size() - 1;
		int parent = (child - 1) / 2;
		while (parent >= 0 && this->elements[child] >= this->elements[parent]) {
			if (parent == child) {
				break;
			}
			swap(this->elements[child], this->elements[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
	}
	void heapifyTopDown() {
		if (n == 1) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int curr = this->elements[i];
			int child = i;
			int parent = (child - 1) / 2;
			while (parent >= 0 && this->elements[child] >= this->elements[parent]) {
				if (parent == child) {
					break;
				}
				swap(this->elements[child], this->elements[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
		}
	}
	void deletion() {
		if (this->n <= 0) {
			return;
		}
		int first = 0;
		int last = this->elements.size() - 1;
		swap(this->elements[first], this->elements[last]);
		this->elements.pop_back();
		this->n--;
		int parent = 0;
		int leftIndex = 2 * parent + 1;
		int rightIndex = 2 * parent + 2;
		while (rightIndex <= n - 1 &&
		        (this->elements[parent] <= this->elements[leftIndex] ||
		         this->elements[parent] <= this->elements[rightIndex])) {
			int leftChild = this->elements[leftIndex];
			int rightChild = this->elements[rightIndex];
			if (leftChild > rightChild) {
				swap(this->elements[parent], this->elements[leftIndex]);
				parent = leftIndex;
				leftIndex = 2 * parent + 1;
				rightIndex = 2 * parent + 2;
			} else {
				swap(this->elements[parent], this->elements[rightIndex]);
				parent = rightIndex;
				leftIndex = 2 * parent + 1;
				rightIndex = 2 * parent + 2;
			}
		}
	}
	void printElements() {
		for (int i = 0; i < this->elements.size(); i++) {
			cout << this->elements[i] << " ";
		}
		cout << endl;
	}
};
void solve() {
	//code goes here
	int n;
	cin >> n;
	vector<int> elements(n);
	for (int i = 0; i < n; i++) {
		cin >> elements[i];
	}
	heap h1(n, elements);
	h1.printElements();
	cout << "enter elements" << endl;
	int k;
	cin >> k;
	// for (int i = 0; i < k; i++) {
	// 	int a;
	// 	cin >> a;
	// 	h1.insertElements(a);
	// 	h1.printElements();
	// }
	for (int i = 0; i < k; i++) {
		h1.deletion();
		h1.printElements();
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