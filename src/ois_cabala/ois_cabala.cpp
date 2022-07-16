#include <iostream>
#include <vector>
#pragma GCC optimize("Ofast")
using namespace std;
typedef unsigned long long ll;
typedef uint8_t sh;

constexpr ll maxn = 393216;
constexpr ll pows[19] = {
	1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,
	10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000,
	1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000
};

ll n, mod, fd;
ll v[19][maxn];
ll idx[19];

inline void generate(sh i, ll pn, sh fd) {
	if (i == 18) return;

	if (fd != 3) {
		v[i][idx[i]++] = pn + pows[i] * 3;
		generate(i+1, pn + pows[i] * 3, 3);
	}
	if (fd != 6) {
		v[i][idx[i]++] = pn + pows[i] * 6;
		generate(i+1, pn + pows[i] * 6, 6);
	}
	if (fd != 9) {
		v[i][idx[i]++] = pn + pows[i] * 9;
		generate(i+1, pn + pows[i] * 9, 9);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T; cin >> T;
	generate(0, 0, 0);
	while (T--) {
		cin >> n >> mod;
		ll res = 0;
		for (ll i = 0; i < n; i++)
			for (int j = 0; j < idx[i]; j++)
				res = max(res, v[i][j] % mod);
		cout << res << ' ';
	}
}

