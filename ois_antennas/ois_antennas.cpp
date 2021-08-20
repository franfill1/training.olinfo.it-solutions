#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < ll , ll > ii;

ll inf = 1ll<<60;

ll getTime(ll S, ll T, ll t)
{
	if (t < S)
	{
		return S;
	}
	else
	{
		t -= S;
		t = T * (t / T + 1) + S;
	}
	return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll N, D;
	cin >> N >> D;
	
	ll L, P, S, T;
	cin >> L >> P >> S >> T;
	
	map < ll ,  ll > sig;
	sig[P] = S;
	
	ll ans = S;
	
	for (ll i = 1; i < N; i++)
	{
		cin >> L >> P >> S >> T;
		L += i * D;
		ans = inf;
		auto it = sig.upper_bound(L-1);
		if (it != sig.end()) ans = it->second;
		
		if (ans != inf)
		{
		    ans = getTime(S, T, ans);
		    it = sig.upper_bound(P + i * D - 1);
		    if (it == sig.end() || it->second > ans)
		    {
		    	sig[P + i*D] = ans;
		    	auto itt = sig.find(P + i*D);
		    	for (it = sig.upper_bound(L-1); it != itt; it++)
		    	{
		    		if (it->second > ans)
		    		{
		    		    sig.erase(it, itt);
		    			break;
					}
				}
		    }
		}
	}
	if (ans == inf) cout << -1;
	else cout << ans;
}