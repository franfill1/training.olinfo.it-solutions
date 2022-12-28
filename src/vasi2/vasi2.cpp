#include<bits/stdc++.h>
using namespace std;

struct node
{
	int priority, a, b, size;
	node *left = nullptr, *right = nullptr;
	node(int a_, int b_) : a(a_) , b(b_), priority(rand())
	{
		recalc();
	}

	~node()
	{
		delete left;
		delete right;
	}

	void recalc()
	{
		size = b-a;
		if (left) 
			size += left->size;
		if (right)
			size += right->size;
	}
};

node *merge(node *l, node *r)
{
	if (!l)
		return r;
	if (!r)
		return l;

	if (l->priority > r->priority)
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

pair < node* , node* > split(node *n, int x)
{
	if (!n) 
		return {nullptr, nullptr};
	if (n->left != nullptr)
	{
		if (n->left->size >= x)
		{
			auto [L, r] = split(n->left, x);
			n->left = r;
			n->recalc();
			return {L, n};
		}
		x -= n->left->size;
	}
	if (n->b - n->a >= x)
	{
		if (n->b - n->a == x)
		{
			auto R = n->right;
			n->right = nullptr;
			n->recalc();
			return {n, R};
		}
		else
		{
			node *L = merge(n->left, x?new node(n->a, n->a + x):nullptr);
			n->a += x;
			n->left = nullptr;
			n->recalc();
			return {L, n};
		}
	}
	else
	{
		x -= n->b - n->a;
		auto [l, R] = split(n->right, x);
		n->right = l;
		n->recalc();
		return {n, R};
	}
}

ostream &operator << (ostream &os, node *n)
{
	if (!n)
		return os;
	os << n->left << "(" << n->a << "," << n->b << ")" << n->right;
	return os;
}

int get(node *n, int pos)
{
	assert(n != nullptr);
	if (n->left != nullptr)
	{
		if (n->left->size > pos)
			return get(n->left, pos);
		pos -= n->left->size;
	}

	if (pos < n->b - n->a)
		return n->a + pos;
	else
	{
		assert(n->right != nullptr);
		pos -= n->b - n->a;
		return get(n->right, pos);
	}
}

pair < node*, node* > extract(node *n, int pos)
{
	auto [L, r] = split(n, pos);
	auto [x, R] = split(r, 1);
	n = merge(L, R);
	return {n, x};
}

int main()
{
    srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	node *root = new node(0, N);
	char q;
	while(Q--)
	{
		cin >> q;
		if (q == 'c')
		{
			int p;
			cin >> p;
			cout << get(root, p) << " ";
		}
		else
		{
			int x, y;
			cin >> x >> y;	
			node *n;
			tie(root, n) = extract(root, x);
			auto [l, R] = split(root, y);
			auto L = merge(l, n);
			root = merge(L, R);
		}
	}
	cout << "\n";
	delete root;
}
