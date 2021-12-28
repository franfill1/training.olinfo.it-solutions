#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using ll = long long;
using vii = vector<ii>;

// SFINAE, exclude string
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator <<(std::ostream &__out, C __container) {
    __out << '{';
    bool first = true;
    for (auto& x : __container) {
        if(!first) __out << ", "; __out << x;
        first = false;
    }
    return __out << '}';
}

template<typename F, typename S>
ostream& operator <<(ostream &__out, pair<F, S> __p) {
    return __out << '(' << __p.first << ',' << ' ' << __p.second << ')';
}

void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }

#ifdef DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define EPS numeric_limits<double>::epsilon()

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<double>> mat(n, vector<double>(m, 0.0)); // max

    for(int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        mat[u][v] = 1.0 - (w / 1000.0);
    }

    for(int u = 0; u < n; ++u)
        mat[u][u] = 1.0; // self edge

    // max path
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {

                double newv = mat[i][k] * mat[k][j];
               
                if(newv > mat[i][j]) {
                    mat[i][j] = newv;
                }
            }
        }
    }

    dbg(mat);

    // scegli il percorso piu' costoso

    double maxv = 1000.0;
    ii ans = {0, 0};

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(mat[i][j] < maxv) {
                maxv = mat[i][j];
                ans = make_pair(i, j);
            }
        }
    }

    dbg(mat);
    printf("%d %d\n", ans.first, ans.second);

    return 0;
}