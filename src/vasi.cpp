#include<bits/stdc++.h>
using namespace std;

struct Treap
{
	int size;
	int priority;
	int val;
	Treap * left = NULL, *right = NULL;

	Treap(int v, int p) : size(1), val(v) , priority(p) {}

	void recalc()
	{
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

pair < Treap* , Treap* > split(Treap *T, int X)
{
	if(!T) return {NULL , NULL};
	int lsize = T->left?T->left->size:0;
	if(lsize < X)
	{
		auto [l, R] = split(T->right, X-lsize-1);
		T->right = l;
		T->recalc();
		return {T, R};
	}
	else
	{
		auto [L, r] = split(T->left, X);
		T->left = r;
		T->recalc();
		return {L, T};
	}
}

Treap* merge(Treap *L, Treap *R)
{
	if (!L) return R;
	if (!R) return L;
	if (!R && !L) return NULL;
	if (L->priority > R->priority)
	{
		L->right = merge(L->right, R);
		L->recalc();
		return L;
	}
	else
	{
		R->left = merge(L, R->left);
		R->recalc();
		return R;
	}
}

int find_by_order(Treap *T, int p)
{
	if (p >= T->size) return -1;
	assert(T);
	int lsize = T->left?T->left->size:0;
	if (lsize == p) return T->val;
	if (lsize < p) return find_by_order(T->right, p-lsize-1);
	else return find_by_order(T->left, p);
}

void print(Treap *T)
{
	if (!T) return;
	print(T->left);
	cout << T->val << ", ";
	print(T->right);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	Treap *T = new Treap(0, rand());
	for (int i = 1; i < n; i++)
	{
		T = merge(T, new Treap(i, rand()));
	}
	//print(T); cout << "\n";

	while(q--)
	{
		char t;
		cin >> t;
		if (t == 'c')
		{
			int p;
			cin >> p;
			cout << find_by_order(T, p) << " ";
		}
		else
		{
			int i, j;
			cin >> i >> j;
			auto [l, R] = split(T, i+1);
			auto [L, S] = split(l, i);
			assert(S->size == 1);
			T = merge(L, R);
			tie(L, R) = split(T, j);
			T = merge(merge(L, S), R);
			//print(T); cout << "\n";
		}
	}
	cout << "\n";
}
