// template by CC
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <vector>
#include <tuple>
#include <queue>

#define mp make_pair
#define pb push_back
#define ins insert
#define f first
#define s second
#define LSOne(S) ((S) & -(S))
#define ctz(S) log2(LSOne(S))

constexpr int INF = 1e9;
constexpr long long LLINF = 4e18;
constexpr double EPS = 1e-9;

using namespace std;
using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
ll GCD(ll a, ll b) { return (b == 0 ? a : GCD(b, a % b)); }
int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a % b)); }
ll LCM(ll a, ll b) { return (a * b) / GCD(a, b); }
int LCM(int a, int b) { return (a * b) / GCD(a, b); }

int N, P;
vector<tuple<int, int, int>> a;
vector<vector<vector<bool>>> b;

int dist[505][505][60];

int al[5] = { -1, 0, 0, 0, 1 };
int be[5] = { 0, -1, 0, 1, 0 };

bool valid(int i, int j, int time) {
    if (i >= N || j >= N || i < 0 || j < 0)
        return false;
    if (b[time][i][j] == 1)
        return false;

    return true;
}

void solve()
{
    queue<tuple<int, int, int>> q;

    dist[0][0][0] = 0;
    q.emplace(0, 0, 0);

    while (!q.empty()) {
        auto& [x, y, time] = q.front(); q.pop();
        for (int d = 0; d < 5; d++)
        {
            if (valid(x + al[d], y + be[d], (time + 1) % 60) && dist[x + al[d]][y + be[d]][(time + 1) % 60] == -1) {
                dist[x + al[d]][y + be[d]][(time + 1) % 60] = dist[x][y][time] + 1;
                q.emplace(x + al[d], y + be[d], (time + 1) % 60);
            }
        }

    }
}

void paint(int i, int j, int time) {
    if (i < 0 || i >= N || j < 0 || j >= N)
        return;

    b[time][i][j] = true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P;

    memset(dist, -1, sizeof dist);

    a.resize(P);
    b.assign(60, vector<vector<bool>>(N, vector<bool>(N, false)));

    for (int i = 0; i < P; ++i) {
        cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
        get<0>(a[i])--;
        get<1>(a[i])--;
    }

    for (int k = 0; k < 60; ++k) {
        for (int r = 0; r < P; ++r) {
            // paint

            auto& [x, y, o] = a[r];

            int t = k % o;

            for (int i = -t; i <= +t; i++) {
                for (int j = abs(i) - t; j <= t - abs(i); j++) {
                    paint(x + i, y + j, k);
                }
            }
        }
    }

    solve();

    int ans = INF;

    for (int k = 0; k < 60; ++k) {
        if(dist[N-1][N - 1][k] != -1) 
            ans = min(ans, dist[N-1][N - 1][k]);
    }

    cout << ans << '\n';

    return 0;
}
