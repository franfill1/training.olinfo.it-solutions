#pragma gcc optimize("O3")
#include<bits/stdc++.h>
using namespace std;
constexpr int MAXV = 1000100;
constexpr int PRIME_CNT = 78504;
constexpr int MAXN = 100000;
constexpr int MAXQ = 100000;
constexpr int P = 17;
constexpr int MEX_BLOCK_SIZE = 447;
constexpr int MEX_BLOCK_COUNT = PRIME_CNT / MEX_BLOCK_SIZE + 2;
constexpr int BLOCK_SIZE = 447;
vector < int > primes;
int pos[MAXV];
bool composite[MAXV];

inline __attribute__((always_inline)) void sieve()
{
	composite[0] = composite[1] = 0;
	pos[0] = pos[1] = PRIME_CNT;
	for (int i = 2; i < MAXV; i++)
	{
		if (!composite[i])
		{
			pos[i] = primes.size();
			primes.emplace_back(i);
		}
		for (auto &p : primes)
		{
			if (i*p >= MAXV)
				break;
			composite[i*p] = true;
			pos[i*p] = PRIME_CNT;
			if (i % p == 0)
				break;
		}
	}
}

int mex_freq[PRIME_CNT];
int block_count[MEX_BLOCK_COUNT];
inline __attribute__((always_inline)) void mex_insert(int x)
{
	// insert a value in the multiset
	if (mex_freq[x]++ == 0)
		block_count[x/MEX_BLOCK_SIZE]++;
}
inline __attribute__((always_inline)) void mex_erase(int x)
{
	// erase a value from the multiset
	if (--mex_freq[x] == 0)
		block_count[x/MEX_BLOCK_SIZE]--;
}

inline __attribute__((always_inline)) int mex_get()
{
	for (int b = 0; b < MEX_BLOCK_COUNT; b++)
		if (block_count[b] < MEX_BLOCK_SIZE)
		{
			for (int i = 0; i < MEX_BLOCK_SIZE; i++)
				if (mex_freq[b*MEX_BLOCK_SIZE+i] == 0)
					return b*MEX_BLOCK_SIZE + i;
			assert(false || MEX_BLOCK_COUNT == b-1);
		}
}

int val[MAXN], flattened[MAXN*2], start[MAXN], fin[MAXN], depth[MAXN], order[MAXQ], ans[MAXQ], q_lca[MAXQ];
int anc[P][MAXN];
bool freq[MAXN];
pair < int , int > quer[MAXQ];
pair < int , int > mapped_quer[MAXQ];
vector < int > g[MAXN];
int t=0, l=0, r=0;

void dfs (int x, int p)
{
	depth[x] = (p == -1) ? 0 : (depth[p]+1);
	anc[0][x] = (p == -1) ? x : p;
	start[x] = t;
	flattened[t++] = x;
	for (int &y : g[x])
		if (y != p)
			dfs(y, x);
	fin[x] = t;
	flattened[t++] = x;
};

inline __attribute__((always_inline)) int kanc (int x, int k)
{
	// get the kth ancestor of a node
	for (int p = 0; p < P; p++)
		if (k & (1<<p))
			x = anc[p][x];
	return x;
};

inline __attribute__((always_inline)) int lca (int a, int b)
{
	// get the lca of two nodes
	if (depth[a] > depth[b])
		swap(a, b);
	b = kanc(b, depth[b] - depth[a]);
	if (a == b)
		return a;
	for (int p = P-1; p >= 0; p--)
		if (anc[p][a] != anc[p][b])
			a = anc[p][a], b = anc[p][b];
	return anc[0][a];
};


inline __attribute__((always_inline)) void toggle (int i)
{
	// toggle the node at position i in flattened tree
	int node = flattened[i];
	if (freq[node])
		freq[node] = 0, mex_erase(val[node]);
	else
		freq[node] = 1, mex_insert(val[node]);
};

inline __attribute__((always_inline)) void move_interval (int nl, int nr)
{
	// move the interval to [nl, nr)
	if (l == r)
		l = nl, r = nl;
	while(l > nl)
		toggle(--l);
	while(l < nl)
		toggle(l++);
	while(r > nr)
		toggle(--r);
	while(r < nr)
		toggle(r++);
};

inline __attribute__((always_inline)) int fast_read_int()
{
    int c, n = 0;
    do
    {
        c = getchar_unlocked();
    } while (c < '0' || c > '9');
    do
    {
        n = (n << 3) + (n << 1) + (c - '0');
        c = getchar_unlocked();
    } while (c >= '0' && c <= '9');
    return n;
}

int main()
{
	cout.tie(NULL);
	// SIEVE INITIALIZATION //
	sieve();
	// INPUT //
	int n = fast_read_int(), q;
	for (int i = 0; i < n; i++)
		val[i] = pos[fast_read_int()];
	for (int i = 0; i < n-1; i++)
	{
		int a = fast_read_int()-1, b = fast_read_int()-1;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	// DFS 
	// - flatten the tree
	// - compute values for lca 
	dfs(0, -1);

	// LCA INITIALIZATION //
	for (int p = 1; p < P; p++)
		for (int i = 0; i < n; i++)
			anc[p][i] = anc[p-1][anc[p-1][i]];

	// PROCESS THE QUERIES //

	q = fast_read_int();
	for (int i = 0; i < q; i++)
	{
		int x = fast_read_int()-1, y = fast_read_int()-1;
		if (start[x] > start[y])
			swap(x, y);
		if (fin[x] > fin[y])
			mapped_quer[i] = make_pair(start[x], start[y]+1),
				q_lca[i] = -1;
		else
			mapped_quer[i] = make_pair(fin[x], start[y]+1),
				q_lca[i] = lca(x, y);
	}

	iota(order, order+q, 0);
	sort(order, order+q, [&] (int i, int j)
			{
				auto &[il, ir] = mapped_quer[i];
				auto &[jl, jr] = mapped_quer[j];
				if (il / BLOCK_SIZE != jl / BLOCK_SIZE)
					return (il / BLOCK_SIZE) < (jl / BLOCK_SIZE);
				else if ((il / BLOCK_SIZE) % 2)
					return ir > jr;
				else
					return ir < jr;
			});
	
	for (int j = 0; j < q; j++)
	{
		int i = order[j];
		auto [nl, nr] = mapped_quer[i];
		move_interval(nl, nr);	
		if (q_lca[i] != -1)
		{
			mex_insert(val[q_lca[i]]);
			ans[i] = primes[mex_get()];
			mex_erase(val[q_lca[i]]);
		}
		else
			ans[i] = primes[mex_get()];
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
}
