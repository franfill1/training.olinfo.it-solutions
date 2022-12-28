#include<set>
using namespace std;

set < long long > A;

void inizia() {
    return;
}

void apri(long long p) {
	A.insert(p);
}

void chiudi(long long p) {
	A.erase(p);
}

long long chiedi(long long p) {
	if (!A.size())
		return -1;
	auto it = A.lower_bound(p);
	long long ans = 1ll<<62;
	if (it != A.end())
		ans = *it;
	if (it != A.begin() && ans + *prev(it) > p<<1)
		ans = *prev(it);
	return ans;
}
