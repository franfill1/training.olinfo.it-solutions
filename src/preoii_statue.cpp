// @check-accepted: esempi positivi decrescenti generale
#include <vector>
using namespace std;
#define ll long long
ll somma(int a, int b);
ll subarray_massimo(int a, int b);
ll subarray_minimo(int a, int b);
static const ll INF = 2e13;
static const int blocks = 27;
struct node {
    ll max_pref, max_suff, somma, max_sub;
    node(ll a = -INF) {
        max_pref = a;
        max_suff = a;
        somma = a;
        max_sub = a;
    }
    node merge(node b) {
        node ans;
        ans.max_pref = max(max_pref, somma + b.max_pref);
        ans.max_suff = max(b.max_suff, b.somma + max_suff);
        ans.somma = somma + b.somma;
        ans.max_sub = max(max(max_sub, b.max_sub), max_suff + b.max_pref);
        return ans;
    }
};
int estremo(int a, int b, ll x) {
    int l = a, r = b;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (subarray_massimo(m, b) == x)
            l = m;
        else
            r = m - 1;
    }
    return l;
}

node cur;
node calc(int a, int b, bool pref, bool suff) {
    node ans;
    ans.max_sub = subarray_massimo(a, b);
    // ans.somma = somma(a, b);
    int x = estremo(a, b, ans.max_sub);
    if (pref && suff) ans.somma = 0;
    if (pref) {
        ll pref_tot = 0;
        if (a != x) pref_tot = somma(a, x - 1);
        ll pref_mi = INF;
        if (a != x) pref_mi = subarray_minimo(a, x - 1);
        ans.max_pref = max(pref_tot + ans.max_sub, pref_tot - pref_mi);
        ans.somma += pref_tot;
    }
    if (suff) {
        ll suff_tot = somma(x, b);
        ll suff_mi = INF;
        if (x != b) suff_mi = subarray_minimo(x + 1, b);
        ans.max_suff = max(suff_tot, suff_tot - suff_mi - ans.max_sub);
        ans.somma += suff_tot;
    }
    return ans;
}
long long trova(int N) {
    int ini = 0;
    for (int i = 0; i < blocks; i++) {
        int x = N * (i + 1) / blocks;
        cur = cur.merge(calc(ini, x - 1, i > 0 && cur.max_suff > 0, i < blocks - 1));
        ini = x;
    }
    return cur.max_sub;
}
