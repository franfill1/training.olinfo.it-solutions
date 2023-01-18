// @check-accepted: esempi easy esponenziale only_one n^3 n^3_opt

#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	std::vector<int> prevs;
	int l;
};

int conta(int n, vector<int> d) {
	std::vector<int> pos(2 * n, -1);
	for (int i = 0; i < n; ++i) {
		pos[d[i]] = i;
	}

	std::vector<node> stks(n + 1);

	for (int i = 0; i < n; ++i) {
		sort(stks[i].prevs.begin(), stks[i].prevs.end());

		stks[i + 1].l = stks[i].l + 1;
		stks[i + 1].prevs.push_back(i);
		for (auto p : stks[i].prevs) {
			auto q = pos[d[i] ^ d[p]];
			if (q == -1) continue;
			if (!binary_search(stks[p].prevs.begin(), stks[p].prevs.end(), q)) continue;

			stks[i + 1].prevs.insert(stks[i + 1].prevs.end(), stks[q].prevs.begin(), stks[q].prevs.end());
			stks[i + 1].l = std::min(stks[i + 1].l, stks[q].l);
		}
	}

	return n - stks[n].l;
}
