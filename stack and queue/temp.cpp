// https://www.codechef.com/problems/MCO16404
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pll pair<ll, ll>
#define vpll vector<pll>
#define gpll greater<pll>
#define pllpll pair<ll, pll>
#define vpllpll vector<pllpll>
#define gpllpll greater<pllpll>
#define pqMin priority_queue<pllpll, vpllpll, gpllpll>
ll MOD = 1e9 + 7;

#define endl "\n"

#ifndef ONLINE_JUDGE
#define deb(x) cout << #x << " = " << x << endl;
#else
#define deb(x)
#endif

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

ll N = 3e5 + 100;

ll n, q;

vector<ll> v(N + 1);

struct trieNode
{
	trieNode *left;

	trieNode *right;

	trieNode()
	{
		this->left = NULL;

		this->right = NULL;
	}
};

vector<trieNode *> tree(4 * N + 10);

ll MAXB = 31;

void insertTrie(ll x, trieNode *root)
{
	trieNode *curr = root;
	for (ll bit = MAXB; bit >= 0; --bit)
	{
		if (x & (1ll << bit))
		{
			if (!curr->right)
			{
				curr->right = new trieNode();
			}

			curr = curr->right;
		}
		else
		{
			if (!curr->left)
			{
				curr->left = new trieNode();
			}

			curr = curr->left;
		}
	}
}

void combine(trieNode *&root, trieNode *root1, trieNode *root2)
{
	if (!root1 && !root2)
		return;

	root = new trieNode();

	if (!root1)
	{
		root = root2;
		return;
	}

	if (!root2)
	{
		root = root1;

		return;
	}

	combine(root->left, root1->left, root2->left);

	combine(root->right, root1->right, root2->right);
}

ll queryTrie(ll x, trieNode *root)
{
	ll res = 0;

	trieNode *curr = root;

	for (ll bit = MAXB; bit >= 0; --bit)
	{

		if (x & (1ll << bit))
		{
			if (curr->left)
			{
				curr = curr->left;

				res += 1ll << bit;
			}
			else
			{
				curr = curr->right;
			}
		}
		else
		{
			if (curr->right)
			{

				curr = curr->right;

				ll p = 1ll << bit;

				res += 1ll << bit;
			}
			else
			{

				curr = curr->left;
			}
		}
	}

	return res;
}

void buildTree(ll ss, ll se, ll node)
{
	if (ss == se)
	{
		tree[node] = new trieNode();

		insertTrie(v[ss], tree[node]);

		return;
	}

	ll mid = ss + (se - ss) / 2;

	buildTree(ss, mid, 2 * node);

	buildTree(mid + 1, se, 2 * node + 1);

	combine(tree[node], tree[2 * node], tree[2 * node + 1]);
}

ll query(ll ss, ll se, ll qs, ll qe, ll node, ll x)
{
	if (qs <= ss && qe >= se)
	{
		ll a = queryTrie(x, tree[node]);

		return a;
	}

	if (qs > se || ss > qe)
		return 0;

	ll mid = ss + (se - ss) / 2;

	ll p = query(ss, mid, qs, qe, 2 * node, x);

	ll q = query(mid + 1, se, qs, qe, 2 * node + 1, x);

	return max(p, q);
}
int binarySearch(vector<pair<int, int>> arr, int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid].first == x)
			return arr[mid].second;
		if (arr[mid].first > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}
void solve()
{
	cin >> n;

	vector<pair<int, int>> temp;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
		temp.push_back(make_pair(v[i], i));
	}

	buildTree(1, n, 1);

	cin >> q;

	for (ll i = 1; i <= q; ++i)
	{
		ll l, r, x;

		cin >> l >> r >> x;

		ll ans = query(1, n, l, r, 1, x);

		deb(ans);

		cout << ans << endl;
		int element = (ans ^ x);
		cout << "element = " << element << endl;
		int index = binarySearch(temp, l - 1, r - 1, element);
		cout << "index = " << index << endl;
	}
}

int main()
{
	// init();
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
}
