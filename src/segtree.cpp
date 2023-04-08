#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

struct segtree
{
    struct node
    {
        ll size=1, sum=0, min=1ll<<60;
        ll add=0, set;
        bool ts=0;

        node(){};
        node(ll v) : size(1) , sum(v) , min(v) {}
    };

    void merge(node &c, node &a, node &b)
    {
        c.sum = a.sum + b.sum;
        c.size = a.size + b.size;
        c.min = min(a.min, b.min);
    }

    vector < node > T;
    int n;

    segtree(vector < ll > a)
    {
        for (n = 1; n < a.size(); n<<=1);
        T.resize(n<<1);
        for (int i = 0; i < a.size(); i++) T[n+i] = node(a[i]);
        for (int k = n-1; k; k--) merge(T[k], T[k*2], T[k*2+1]);
    }

    void prop(int k)
    {
        if (T[k].ts)
        {
            T[k].sum = T[k].size * T[k].set;
            T[k].min = T[k].set;
        }
        T[k].sum += T[k].size * T[k].add;
        T[k].min += T[k].add;
        if (k < n)
        {
            int a = k*2, b = k*2+1;
            if (T[k].ts)
            {
                T[a].ts = T[b].ts = 1;
                T[a].set = T[b].set = T[k].set;
                T[a].add = T[b].add = 0;
            }
            T[a].add += T[k].add;
            T[b].add += T[k].add;
        }
        T[k].add = T[k].ts = 0;
    }

    ll get_sum(int l, int r, int k = 1, int x = 0, int y = -1)
    {
        if (y == -1) y = n;
        prop(k);
        if (l <= x && y <= r) return T[k].sum;
        if (r <= x || y <= l) return 0;
        int m = (x+y)>>1;
        return get_sum(l, r, k*2, x, m) + get_sum(l, r, k*2+1, m, y);
    }

    void add(int l, int r, ll v, int k = 1, int x = 0, int y = -1)
    {
        if (y == -1) y = n;
        if (l <= x && y <= r)
        {
            T[k].add += v;
        }
        prop(k);
        if (l <= x && y <= r) return;
        if (r <= x || y <= l) return;
        int m = (x+y)>>1;
        add(l, r, v, k*2, x, m);
        add(l, r, v, k*2+1, m, y);
        merge(T[k], T[k*2], T[k*2+1]);
    }
    
    void set_range(int l, int r, ll v, int k = 1, int x = 0, int y = -1)
    {
        if (y == -1) y = n;
        if (l <= x && y <= r)
        {
            T[k].ts = 1;
            T[k].add = 0;
            T[k].set = v;
        }
        prop(k);
        if (l <= x && y <= r) return;
        if (r <= x || y <= l) return;
        int m = (x+y)>>1;
        set_range(l, r, v, k*2, x, m);
        set_range(l, r, v, k*2+1, m, y);
        merge(T[k], T[k*2], T[k*2+1]);
    }
    
    ll get_min(int l, int r, int k = 1, int x = 0, int y = -1)
    {
        if (y == -1) y = n;
        prop(k);
        if (l <= x && y <= r) return T[k].min;
        if (r <= x || y <= l) return 1ll<<60;
        int m = (x+y)>>1;
        return min(get_min(l, r, k*2, x, m), get_min(l, r, k*2+1, m, y));
    }

    int lower_bound(int l, int r, ll v, int k = 1, int x = 0, int y = -1)
    {
        if (y == -1) y = n;
        prop(k);
        if (r <= x || y <= l) return -1;
        if (T[k].min > v) return -1;
        if (x == y-1) return x;
        int m = (x+y)>>1;
        int res = lower_bound(l, r, v, k*2, x, m);
        if (res == -1) res = lower_bound(l, r, v, k*2+1, m, y);
        return res;
    }
};

segtree *seg;

void init(vector<long long> a) {
    seg = new segtree(a);
}

long long get_sum(int l, int r) {
    return seg->get_sum(l, r);
}

void add(int l, int r, long long x) {
    seg->add(l, r, x);
}

void set_range(int l, int r, long long x) {
    seg->set_range(l, r, x);
}

long long get_min(int l, int r) {
    return seg->get_min(l, r);
}

int lower_bound(int l, int r, long long x) {
    return seg->lower_bound(l, r, x);
}
