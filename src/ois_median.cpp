#include<bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;

struct node {
	int key, val, size, prior;
	node* left = nullptr;
	node* right = nullptr;

	node(int k, int v)
	{
		key = k;
		size = val = v;
		prior = rand();
	}
	
	~node()
	{
		delete left;
		delete right;
	}

	void recalc()
	{
		size = (left ? left->size : 0) + (right ? right->size : 0) + val;
	}
};

pair < node* , node* > split(node* x, int piv)
{
	if (!x)
		return make_pair(nullptr, nullptr);
	if (x->key <= piv)
	{
		auto [l, R] = split(x->right, piv);
		x->right = l;
		x->recalc();
		return make_pair(x, R);
	}
	else 
	{
		auto [L, r] = split(x->left, piv);
		x->left = r;
		x->recalc();
		return make_pair(L, x);
	}
}

node* merge(node* l, node* r)
{
	if (!l)
		return r;
	if (!r)
		return l;
	if (l->prior > r->prior)
	{
		l->right = merge(l->right, r);
		l->recalc();
		return l;
	}
	else 
	{
		r->left = merge(l, r->left);	
		r->recalc();
		return r;
	}
}

bool add(node* x, int key, int val)
{
	if (!x)
		return false;
	bool ok;
	if (x->key == key)
		ok = true, x->val += val;
	if (x->key > key)
		ok = add(x->left, key, val);
	if (x->key < key)
		ok = add(x->right, key, val);
	if (ok)
		x->recalc();
	return ok;
}

node* insert(node* treap, int key, int val)
{
	if (!add(treap, key, val))
	{
		auto [l, r] = split(treap, key);	
		auto n = new node(key, val);
		treap = merge(l, n);
		treap = merge(treap, r);
	}
	return treap;
}

int order_of_key(node *x, int key)
{
	if (!x)
		return 0;
	if (x->key == key)
		return x->left ? x->left->size : 0;
	else if (x->key > key)
		return order_of_key(x->left, key);
	else if (x->key < key)
		return (x->left ? x->left->size : 0) + x->val + order_of_key(x->right, key);
	return 0;
}

void collect (node* x, vector < pair < int , int > > &v)
{
	if (!x)
		return;
	collect(x->left, v);
	v.emplace_back(make_pair(x->key, x->val));
	collect(x->right, v);
}

const int MAXN = 50000;
vector < pair < int , int > > g[MAXN];
node* s[MAXN];

int tr;
int dfs(int x=0, int p=-1, int d=0)
{
	s[x] = new node(d, 1);
	assert(s[x]->size == 1);
	int ans = 0;
	for (auto [y, v] : g[x])
		if (y != p)
		{
			int w = (v <= tr) ? -1 : 1;
			ans += dfs(y, x, d+w);
			if (s[y]->size > s[x]->size)
				swap(s[x], s[y]);
		}
	for (auto [y, i] : g[x])
		if (y != p)
		{
			vector < pair < int , int > > col;
			collect(s[y], col);
			delete s[y];
			for (auto [k, v] : col)
				ans += order_of_key(s[x], 1 - k + 2*d) * v;
			for (auto [k, v] : col)
				s[x] = insert(s[x], k, v);
		}
	return ans;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector < int > ws;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
		ws.emplace_back(w);
	}
	sort(ws.begin(), ws.end());
	int l = -1, r = ws.size() - 1;
	while(l < r - 1)
	{
		int m = (l+r)/2;
		tr = ws[m];
		int t = dfs();
		delete s[0];
		if (t < k)
			l = m;
		else
			r = m;
	}
	cout << ws[r] << "\n";
}
