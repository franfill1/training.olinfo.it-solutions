#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll A, B, T;
	cin >> A >> B >> T;
	ll d = B-A;
	ll ans = T/24 * d;

	T %= 24;
	ans += max(0ll, T-(24+A-B));
	
	cout << ans << "\n";
}
